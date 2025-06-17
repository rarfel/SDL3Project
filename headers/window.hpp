#pragma once

#include "../vendor/SDL/include/SDL3/SDL.h"
#include "../vendor/SDL_image/include/SDL3_image/SDL_image.h"
#include <string>
#include <memory>
#include <optional>
#include <iostream>

enum class WindowState
{
    RUNNING,
    EXIT
};

class Window
{
    std::unique_ptr<SDL_Window,decltype(&SDL_DestroyWindow)> windowPointer;
    public:
        explicit Window(const std::string &title, int WIDTH = 1440, int HEIGHT = 720, SDL_WindowFlags flags = SDL_WINDOW_RESIZABLE);
        WindowState state;

        static void Init();
        static void Quit();

        static std::optional<SDL_Event> Event();
        static void Inputs(std::optional<SDL_Event> ev);
        static SDL_Texture* LoadTexture(const char* filePath);

        static SDL_Window* windowP;
        static SDL_Renderer* renderer;

        static SDL_Rect img;
        static SDL_Rect imgLocation;

    private:
        bool movement[4];

};