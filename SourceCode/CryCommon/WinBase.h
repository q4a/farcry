//Is this even needed?
#include <Linux64Specific.h>

#define INVALID_HANDLE_VALUE -1

void RemoveCRLF(std::string& str);
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
static unsigned long timeGetTime(void);
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
HANDLE CreateEvent(
	LPSECURITY_ATTRIBUTES lpEventAttributes,
	BOOL bManualReset,
	BOOL bInitialState,
	LPCSTR lpName
);
typedef DWORD (*PTHREAD_START_ROUTINE)( LPVOID lpThreadParameter );
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;
DWORD WaitForSingleObjectEx(HANDLE hHandle,	DWORD dwMilliseconds,	BOOL bAlertable);
DWORD WaitForSingleObject( HANDLE hHandle,DWORD dwMilliseconds );
const BOOL compareTextFileStrings(const char* cpReadFromFile, const char* cpToCompareWith);
BOOL SetEvent( HANDLE hEvent );
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