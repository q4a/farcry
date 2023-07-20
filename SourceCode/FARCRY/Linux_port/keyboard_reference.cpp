#include <Windows.h>
#include <dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

int main()
{
    // Initialize DirectInput
    HRESULT hr;
    IDirectInput8* pDI = nullptr;
    hr = DirectInput8Create(GetModuleHandle(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&pDI, nullptr);
    if (FAILED(hr))
    {
        // Handle error
        return 1;
    }

    // Initialize the keyboard device
    IDirectInputDevice8* pKeyboard = nullptr;
    hr = pDI->CreateDevice(GUID_SysKeyboard, &pKeyboard, nullptr);
    if (FAILED(hr))
    {
        pDI->Release();
        // Handle error
        return 1;
    }

    // Set the keyboard data format
    hr = pKeyboard->SetDataFormat(&c_dfDIKeyboard);
    if (FAILED(hr))
    {
        pKeyboard->Release();
        pDI->Release();
        // Handle error
        return 1;
    }

    // Set the cooperative level for the keyboard
    hr = pKeyboard->SetCooperativeLevel(GetDesktopWindow(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
    if (FAILED(hr))
    {
        pKeyboard->Release();
        pDI->Release();
        // Handle error
        return 1;
    }

    // Acquire the keyboard
    hr = pKeyboard->Acquire();
    if (FAILED(hr))
    {
        pKeyboard->Release();
        pDI->Release();
        // Handle error
        return 1;
    }

    // Main loop
    while (true)
    {
        // Read the keyboard state
        BYTE keyboardState[256];
        hr = pKeyboard->GetDeviceState(sizeof(keyboardState), keyboardState);
        if (FAILED(hr))
        {
            // If reading failed, try to re-acquire the device
            hr = pKeyboard->Acquire();
            if (FAILED(hr))
            {
                // Handle error
                break;
            }
        }

        // Check if the 'ESC' key is pressed to exit the loop
        if (keyboardState[DIK_ESCAPE] & 0x80)
        {
            break;
        }

        // Do other processing here...

        // Sleep a bit to reduce CPU usage (not recommended in a real-time game)
        Sleep(16);
    }

    // Release and clean up
    pKeyboard->Unacquire();
    pKeyboard->Release();
    pDI->Release();

    return 0;
}
