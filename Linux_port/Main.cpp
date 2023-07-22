#include <iostream>
#include <dlfcn.h>
#include <cstring>

#include <ISystem.h>

static ISystem *g_pISystem=NULL;

void AuthCheckFunction( void *data )
{
	// src and trg can be the same pointer (in place encryption)
	// len must be in bytes and must be multiple of 8 byts (64bits).
	// key is 128bit:  int key[4] = {n1,n2,n3,n4};
	// void encipher(unsigned int *const v,unsigned int *const w,const unsigned int *const k )
#define TEA_ENCODE( src,trg,len,key ) {\
	register unsigned int *v = (src), *w = (trg), *k = (key), nlen = (len) >> 3; \
	register unsigned int delta=0x9E3779B9,a=k[0],b=k[1],c=k[2],d=k[3]; \
	while (nlen--) {\
	register unsigned int y=v[0],z=v[1],n=32,sum=0; \
	while(n-->0) { sum += delta; y += (z << 4)+a ^ z+sum ^ (z >> 5)+b; z += (y << 4)+c ^ y+sum ^ (y >> 5)+d; } \
	w[0]=y; w[1]=z; v+=2,w+=2; }}

	// src and trg can be the same pointer (in place decryption)
	// len must be in bytes and must be multiple of 8 byts (64bits).
	// key is 128bit: int key[4] = {n1,n2,n3,n4};
	// void decipher(unsigned int *const v,unsigned int *const w,const unsigned int *const k)
#define TEA_DECODE( src,trg,len,key ) {\
	register unsigned int *v = (src), *w = (trg), *k = (key), nlen = (len) >> 3; \
	register unsigned int delta=0x9E3779B9,a=k[0],b=k[1],c=k[2],d=k[3]; \
	while (nlen--) { \
	register unsigned int y=v[0],z=v[1],sum=0xC6EF3720,n=32; \
	while(n-->0) { z -= (y << 4)+c ^ y+sum ^ (y >> 5)+d; y -= (z << 4)+a ^ z+sum ^ (z >> 5)+b; sum -= delta; } \
	w[0]=y; w[1]=z; v+=2,w+=2; }}

	// Data assumed to be 32 bytes.
	int key1[4] = {1873613783,235688123,812763783,1745863682};
	TEA_DECODE( (unsigned int*)data,(unsigned int*)data,32,(unsigned int*)key1 );
	int key2[4] = {1897178562,734896899,156436554,902793442};
	TEA_ENCODE( (unsigned int*)data,(unsigned int*)data,32,(unsigned int*)key2 );
}


int main() {
    // Load the .so file
    void* handle = dlopen("libCrySystem.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Failed to load the .so file: " << dlerror() << std::endl;
        return 1;
    }

    // Get the function pointer
    PFNCREATESYSTEMINTERFACE pfnCreateSystemInterface = (PFNCREATESYSTEMINTERFACE)dlsym(handle, "CreateSystemInterface");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Failed to find the function: " << dlsym_error << std::endl;
        dlclose(handle);
        return 1;
    }


    std::cout << "Function located, hold on to your panties..." << std::endl;

    SSystemInitParams sip;

    // Initialize with instance and window handles.
    sip.sLogFileName = "Log.txt";
    sip.hInstance = 0;
    sip.hWnd = NULL;
    sip.pSystem = NULL;
    sip.pCheckFunc = AuthCheckFunction;

    // Call the function
    g_pISystem = pfnCreateSystemInterface(sip);
    if (!g_pISystem) {
        return false;
    }

    std::cout << "Function ran..." << std::endl;

    typedef bool (*PFNCREATEGAME)(void* pISystem);
    //The following string is a accurate representation of my current mental state:
    //echo "_ZN7CSystem10CreateGameERK15SGameInitParams" | c++filt
    PFNCREATEGAME pfnCreateGame = (PFNCREATEGAME)dlsym(handle, "_ZN7CSystem10CreateGameERK15SGameInitParams");

    bool createGameSuccess = false;
    if (pfnCreateGame) {
        // Call the CreateGame function
        std::cout << "Call the CreateGame function" << std::endl;
        //createGameSuccess = pfnCreateGame(g_pISystem);
        //createGameSuccess = g_pISystem->CreateGame;
        SGameInitParams gip;
        gip.sGameDLL = "libCryGame.so";
        createGameSuccess = (g_pISystem->CreateGame)(gip);
    } else {
        std::cerr << "Failed to call CreateGame" << std::endl;

        const char* error = dlerror();
        if (error) {
            std::cout << "Error while getting function address: " << error << std::endl;
        }
    }

    // Unload the .so file
    dlclose(handle);

    return 0;
}