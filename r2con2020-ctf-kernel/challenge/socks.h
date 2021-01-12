#ifndef __SOCKS_H__

#define __SOCKS_H__

#include <linux/spinlock.h>
#include <linux/types.h>

typedef struct sock sock_t;

typedef struct sock_buf {
	size_t size;
	unsigned char *buffer;
	size_t read_index;
	size_t write_index;
} sock_buf_t;

typedef struct sock {
	spinlock_t lock;
	struct list_head listening_list;
	int state;
	sock_t *peer;
	sock_buf_t *buf;
	unsigned char name[64];
} sock_t;

typedef enum {
	UNINITIALIZED = 0,
	INITIALIZED = 1,
	LISTENING = 2,
	CONNECTED = 3,
} sock_state;

// Do we need any other global state?
typedef struct sock_device {
	spinlock_t lock;
	struct list_head listening;
} sock_dev_t;


struct sock_name_param {
	char name[64];
};

struct sock_buffer_param {
	uint64_t size;
	void * __user buffer;
};

#define IOCTL_SOCKS_INIT			_IOWR('s', 1, uint64_t)
#define IOCTL_SOCKS_LISTEN		_IOWR('s', 2, struct sock_name_param)
#define IOCTL_SOCKS_CONNECT		_IOWR('s', 3, struct sock_name_param)
#define IOCTL_SOCKS_SEND			_IOWR('s', 4, struct sock_buffer_param)
#define IOCTL_SOCKS_RECV			_IOWR('s', 5, struct sock_buffer_param)
#define IOCTL_SOCKS_RESIZE		_IOWR('s', 6, uint64_t)



#endif
