// This is a generated source file for Chilkat version 9.5.0.83
#ifndef _C_CkPdf_H
#define _C_CkPdf_H
#include "chilkatDefs.h"

#include "Chilkat_C.h"


CK_C_VISIBLE_PUBLIC HCkPdf CkPdf_Create(void);
CK_C_VISIBLE_PUBLIC void CkPdf_Dispose(HCkPdf handle);
CK_C_VISIBLE_PUBLIC void CkPdf_getDebugLogFilePath(HCkPdf cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkPdf_putDebugLogFilePath(HCkPdf cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkPdf_debugLogFilePath(HCkPdf cHandle);
CK_C_VISIBLE_PUBLIC void CkPdf_getLastErrorHtml(HCkPdf cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkPdf_lastErrorHtml(HCkPdf cHandle);
CK_C_VISIBLE_PUBLIC void CkPdf_getLastErrorText(HCkPdf cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkPdf_lastErrorText(HCkPdf cHandle);
CK_C_VISIBLE_PUBLIC void CkPdf_getLastErrorXml(HCkPdf cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkPdf_lastErrorXml(HCkPdf cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkPdf_getLastMethodSuccess(HCkPdf cHandle);
CK_C_VISIBLE_PUBLIC void CkPdf_putLastMethodSuccess(HCkPdf cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkPdf_getLoadOwnerPassword(HCkPdf cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkPdf_putLoadOwnerPassword(HCkPdf cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkPdf_loadOwnerPassword(HCkPdf cHandle);
CK_C_VISIBLE_PUBLIC void CkPdf_getLoadUserPassword(HCkPdf cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkPdf_putLoadUserPassword(HCkPdf cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkPdf_loadUserPassword(HCkPdf cHandle);
CK_C_VISIBLE_PUBLIC int CkPdf_getNumSignatures(HCkPdf cHandle);
CK_C_VISIBLE_PUBLIC void CkPdf_getUncommonOptions(HCkPdf cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC void CkPdf_putUncommonOptions(HCkPdf cHandle, const char *newVal);
CK_C_VISIBLE_PUBLIC const char *CkPdf_uncommonOptions(HCkPdf cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkPdf_getUtf8(HCkPdf cHandle);
CK_C_VISIBLE_PUBLIC void CkPdf_putUtf8(HCkPdf cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC BOOL CkPdf_getVerboseLogging(HCkPdf cHandle);
CK_C_VISIBLE_PUBLIC void CkPdf_putVerboseLogging(HCkPdf cHandle, BOOL newVal);
CK_C_VISIBLE_PUBLIC void CkPdf_getVersion(HCkPdf cHandle, HCkString retval);
CK_C_VISIBLE_PUBLIC const char *CkPdf_version(HCkPdf cHandle);
CK_C_VISIBLE_PUBLIC BOOL CkPdf_LoadBd(HCkPdf cHandle, HCkBinData pdfData);
CK_C_VISIBLE_PUBLIC BOOL CkPdf_LoadFile(HCkPdf cHandle, const char *filePath);
CK_C_VISIBLE_PUBLIC BOOL CkPdf_SaveLastError(HCkPdf cHandle, const char *path);
CK_C_VISIBLE_PUBLIC BOOL CkPdf_VerifySignature(HCkPdf cHandle, int index, HCkJsonObject sigInfo);
#endif
