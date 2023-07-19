#include <iostream>
#include <signal.h>
#include <pthread.h>

// Global variables
volatile bool g_readError = false;

// Signal handler for SIGSEGV
void segfaultHandler(int signal)
{
    g_readError = true;
    pthread_exit(nullptr);
}

// Thread function to check memory read access
void* checkMemoryAccess(void* address)
{
    // Check for null pointer
    if (address == nullptr)
    {
        g_readError = true;
        pthread_exit(nullptr);
    }

    // Set up the signal handler for SIGSEGV
    struct sigaction sa;
    sa.sa_flags = SA_NODEFER;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = segfaultHandler;
    sigaction(SIGSEGV, &sa, nullptr);

    // Attempt to read the memory
    volatile int* ptr = static_cast<int*>(address);
    volatile int value = *ptr;
    
    // If we reach this point, the memory read was successful
    pthread_exit(nullptr);
}

// Function to check if a pointer is valid for reading
bool IsBadReadPtr(const void* address, size_t size)
{
    pthread_t thread;
    g_readError = false;

    // Create a new thread to check memory access
    if (pthread_create(&thread, nullptr, checkMemoryAccess, const_cast<void*>(address)) != 0)
    {
        std::cerr << "Failed to create thread" << std::endl;
        return true; // Assuming invalid read on failure to create thread
    }

    // Wait for the thread to complete
    if (pthread_join(thread, nullptr) != 0)
    {
        std::cerr << "Failed to join thread" << std::endl;
        return true; // Assuming invalid read on failure to join thread
    }

    return g_readError;
}

// Example usage
int main()
{
    int invalidPtr = 42;  // Uninitialized pointer
    
    bool isBadPtr = IsBadReadPtr(invalidPtr, sizeof(int));
    
    if (isBadPtr)
        std::cout << "Invalid pointer!" << std::endl;
    else
        std::cout << "Valid pointer!" << std::endl;

    return 0;
}
