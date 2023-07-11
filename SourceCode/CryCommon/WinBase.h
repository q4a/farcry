//Is this even needed?
#include <Linux64Specific.h>

void GlobalMemoryStatus(LPMEMORYSTATUS lpmem);
int comparePathNames(const char* cpFirst, const char* cpSecond, const unsigned int len);
bool QueryPerformanceCounter(LARGE_INTEGER *counter);
bool QueryPerformanceFrequency(LARGE_INTEGER *frequency);
DWORD Sleep(DWORD dwMilliseconds);
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
uint64_t __rdtsc();