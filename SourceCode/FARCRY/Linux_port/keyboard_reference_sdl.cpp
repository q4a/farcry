#include <SDL2/SDL.h>

int main()
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0)
    {
        // Handle initialization error
        SDL_Log("SDL initialization failed: %s", SDL_GetError());
        return 1;
    }

    // Create a window (required for event handling)
    SDL_Window* window = SDL_CreateWindow(
        "SDL Keyboard Input Example",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800, 600,
        0
    );

    if (!window)
    {
        // Handle window creation error
        SDL_Log("Failed to create SDL window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Main loop
    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
            }
        }

        // Do other processing here...

        // Sleep a bit to reduce CPU usage (not recommended in a real-time game)
        SDL_Delay(16);
    }

    // Destroy window and quit SDL
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
