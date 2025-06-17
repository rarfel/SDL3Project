#include "../headers/window.hpp"

int main()
{
    Window::Init();

    try
    {
        Window window("Janela");

        window.state = WindowState::RUNNING;
        while(window.state != WindowState::EXIT)
        {
            std::optional<SDL_Event> event;
            while(event = Window::Event())
                Window::Inputs(event);
                switch (event->type)
                {
                    case SDL_EventType::SDL_EVENT_QUIT:
                        window.state = WindowState::EXIT;
                    break;
                }
        }
    }
    catch(const std::exception& e)
    {
        SDL_LogCritical(SDL_LogCategory::SDL_LOG_CATEGORY_ERROR, SDL_GetError());
    }

    Window::Quit();

    return 0;
}