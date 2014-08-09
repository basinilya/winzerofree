#include <windows.h>
#include "mylogging.h"

#define NO_DEBUG_MYPROG
#include "mylastheader.h"

void dbg_LookupPrivilegeValue(LPCTSTR lpSystemName, LPCTSTR lpName, PLUID   lpLuid)
{
	if (!LookupPrivilegeValue(lpSystemName, lpName, lpLuid)) {
		pWin32Error(ERR, "LookupPrivilegeValue() failed");
		abort();
	}
}
void dbg_SetFilePointerEx(HANDLE hFile, LARGE_INTEGER liDistanceToMove, PLARGE_INTEGER lpNewFilePointer, DWORD dwMoveMethod)
{
	if (!SetFilePointerEx(hFile, liDistanceToMove, lpNewFilePointer, dwMoveMethod)) {
		pWin32Error(ERR, "SetFilePointerEx() failed");
		abort();
	}
}
void dbg_CloseHandle(const char *file, int line, HANDLE hObject) {
	if (!CloseHandle(hObject)) {
		pWin32Error(ERR, "CloseHandle() failed at %s:%d", file, line);
		abort();
	}
}

void dbg_WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped)
{
	if (!WriteFile(hFile, lpBuffer, nNumberOfBytesToWrite, lpNumberOfBytesWritten, lpOverlapped)) {
		pWin32Error(ERR, "WriteFile() failed");
		abort();
	}
}
void dbg_ReadFile(HANDLE hFile, LPVOID lpBuffer, DWORD nNumberOfBytesToRead, LPDWORD lpNumberOfBytesRead, LPOVERLAPPED lpOverlapped)
{
	if (!ReadFile(hFile, lpBuffer, nNumberOfBytesToRead, lpNumberOfBytesRead, lpOverlapped)) {
		pWin32Error(ERR, "ReadFile() failed");
		abort();
	}
}
