#include <iostream>

#include "display.hpp"

const int WIDTH = 500, HEIGHT = 500;

Display::Display()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    
    window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if (window == NULL)
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

std::vector<SDL_Event> Display::GetEvents()
{
    std::vector<SDL_Event> events;

    SDL_Event windowEvent;
    while (SDL_PollEvent(&windowEvent))
    {
        events.push_back(windowEvent);
    }

    return events;
}

void Display::Render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    int mouseX;
    int mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.w = mouseX;
    rect.h = mouseY;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);
}

Display::~Display()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}