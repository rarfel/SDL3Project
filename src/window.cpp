#include "../headers/window.hpp"
#include <stdexcept>

Window::Window(const std::string &title, int WIDTH, int HEIGHT, SDL_WindowFlags flags) : windowPointer(SDL_CreateWindow(title.c_str(), WIDTH, HEIGHT, flags), &SDL_DestroyWindow)
{
    if(!windowPointer)
        throw std::runtime_error(SDL_GetError());
    movement[0] = false;
    movement[1] = false;
    movement[2] = false;
    movement[3] = false;

    windowP = SDL_CreateWindow(title.c_str(), WIDTH, HEIGHT, flags);
    renderer = SDL_CreateRenderer(windowP,NULL);
}

void Window::Init()
{
    if(!SDL_InitSubSystem(SDL_INIT_VIDEO))
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, SDL_GetError());
}

void Window::Quit()
{
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

std::optional<SDL_Event> Window::Event()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
        return event;
    else
        return std::nullopt;
}

void Window::Inputs(std::optional<SDL_Event> ev)
{
    if(ev->type == SDL_EVENT_KEY_DOWN)
        switch (ev->key.key)
        {
            case SDLK_H:
                std::cout << "HEAL" <<std::endl;
                break;
            case SDLK_W:
                std::cout << "MOVE UP" <<std::endl;
                break;
            case SDLK_A:
                std::cout << "MOVE LEFT" <<std::endl;
                break;
            case SDLK_S:
                std::cout << "MOVE DOWN" <<std::endl;
                break;
            case SDLK_D:
                std::cout << "MOVE RIGHT" <<std::endl;
                break;
        }
}

SDL_Texture* Window::LoadTexture(const char* filePath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer,filePath);

    if(texture == NULL)
    {
        std::cout << "sem texto: " << filePath << " Error: " << SDL_GetError() << '\n';

    }
    return texture;
}