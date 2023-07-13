#include <iostream>
#include <dlfcn.h>

int main() {
    // Load the .so file
    void* handle = dlopen("libCrySystem.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Failed to load the .so file: " << dlerror() << std::endl;
        return 1;
    }

    // Get the function pointer
    typedef void (*FunctionType)();
    FunctionType function = (FunctionType)dlsym(handle, "CreateSystemInterface");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Failed to find the function: " << dlsym_error << std::endl;
        dlclose(handle);
        return 1;
    }

    std::cout << "Function located, hold on to your panties..." << std::endl;

    // Call the function
    function();

    // Unload the .so file
    dlclose(handle);

    return 0;
}