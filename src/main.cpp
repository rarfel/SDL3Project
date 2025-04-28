#include "../vendor/SDL/include/SDL3/SDL.h"

int main()
{
    int WIDTH = 720; 
    int HEIGHT = 480;
    auto window = SDL_CreateWindow("Teste",WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE);

    if(!window)
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, SDL_GetError());

    bool isPlaying = true;
    while(isPlaying)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
            if(event.type == SDL_EventType::SDL_EVENT_QUIT)
                isPlaying = false;
    }

    SDL_DestroyWindow(window);
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    return 0;
}