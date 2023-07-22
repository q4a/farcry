//Is this even needed?
#include <Linux64Specific.h>

#ifndef INVALID_HANDLE_VALUE
	#define INVALID_HANDLE_VALUE -1
#endif

#define _strlwr strlwr
#define DebugBreak __builtin_trap
void OutputDebugString(const char* message);
void RemoveCRLF(std::string str);
void GlobalMemoryStatus(LPMEMORYSTATUS lpmem);
int comparePathNames(const char* cpFirst, const char* cpSecond, const unsigned int len);
bool QueryPerformanceCounter(LARGE_INTEGER *counter);
bool QueryPerformanceFrequency(LARGE_INTEGER *frequency);
DWORD Sleep(DWORD dwMilliseconds);
DWORD SleepEx( DWORD dwMilliseconds,BOOL bAlertable );
DWORD GetCurrentDirectory( DWORD nBufferLength, char* lpBuffer );
void adaptFilenameToLinux(string& rAdjustedFilename);
const bool GetFilenameNoCase(const char*,char *);
DWORD GetFileAttributes(LPCSTR lpFileName);
void replaceDoublePathFilename(char *szFileName);
uint64 Int32x32To64(uint a, uint b);
char* strlwr (char * str);
int _mkdir(const char *dirname);
BOOL RemoveDirectory(LPCSTR lpPathName);
BOOL DeleteFile(LPCSTR lpFileName);
bool QueryPerformanceFrequency(LARGE_INTEGER *frequency);
bool QueryPerformanceCounter(LARGE_INTEGER *counter);
unsigned long timeGetTime(void);
int memicmp( LPCSTR s1, LPCSTR s2, DWORD len );
HANDLE CreateFile(const char* lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,void* lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
BOOL CloseHandle( HANDLE hObject );
DWORD GetFileSize(HANDLE hFile,DWORD *lpFileSizeHigh );
BOOL CancelIo( HANDLE hFile );
HRESULT GetOverlappedResult( HANDLE hFile,void* lpOverlapped,LPDWORD lpNumberOfBytesTransferred, BOOL bWait );
BOOL ReadFile(
	HANDLE hFile,
	LPVOID lpBuffer,
	DWORD nNumberOfBytesToRead,
	LPDWORD lpNumberOfBytesRead,
	LPOVERLAPPED lpOverlapped
);
BOOL ReadFileEx(
	HANDLE hFile,
	LPVOID lpBuffer,
	DWORD nNumberOfBytesToRead,
	LPOVERLAPPED lpOverlapped,
	LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);
DWORD SetFilePointer(
	HANDLE hFile,
	LONG lDistanceToMove,
	PLONG lpDistanceToMoveHigh,
	DWORD dwMoveMethod
);
DWORD GetCurrentThreadId();
Event* CreateEvent(pthread_mutexattr_t* mutexAttr, bool manualReset, bool initialState, const char* name);
typedef DWORD (*PTHREAD_START_ROUTINE)( LPVOID lpThreadParameter );
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;
int WaitForSingleObjectEx(Event* event, unsigned long milliseconds, bool alertable);
bool WaitForSingleObject(Event* event, unsigned long milliseconds);
//inline char* _fullpath(char* absPath, const char* relPath, size_t maxLength);
void _splitpath(const char* inpath, char * drv, char * dir, char* fname, char * ext );
void _makepath(char * path, const char * drive, const char *dir, const char * filename, const char * ext);
const BOOL compareTextFileStrings(const char* cpReadFromFile, const char* cpToCompareWith);
void SetEvent(Event* event);
HANDLE CreateThread(
	LPSECURITY_ATTRIBUTES lpThreadAttributes,
	SIZE_T dwStackSize,
	LPTHREAD_START_ROUTINE lpStartAddress,
	LPVOID lpParameter,
	DWORD dwCreationFlags,
	LPDWORD lpThreadId
);
BOOL SystemTimeToFileTime( const SYSTEMTIME *syst, LPFILETIME ft );
BOOL SetFileAttributes(LPCSTR lpFileName,DWORD dwFileAttributes );
uint32_t GetTickCount();
uint64_t __rdtsc();
bool IsBadReadPtr(const void* address, size_t size);
BOOL GetFileTime(HANDLE hFile, LPFILETIME lpCreationTime, LPFILETIME lpLastAccessTime, LPFILETIME lpLastWriteTime);
LONG CompareFileTime(const FILETIME *lpFileTime1, const FILETIME *lpFileTime2);
bool MakeSureDirectoryPathExists(const char* path);
char* strupr (char * str);
unsigned int GetCurrentTime();