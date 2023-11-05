#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "model/player.hpp"
#include "model/items.hpp"

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, char *argv[])
{
    Player player = Player();
    std::cout << player.stats.health.level << std::endl;
    std::cout << player.stats.defense.level << std::endl;
    std::cout << player.stats.mana.level << std::endl;

    ItemWoodenSword woodenSword = ItemWoodenSword();
    std::cout << woodenSword.stats.damage.level << std::endl;
    std::cout << woodenSword.stats.critChance.level << std::endl;
    std::cout << woodenSword.stats.critDamage.level << std::endl;

    return 0;

    /*
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    
    SDL_Window *window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);

    if (window == NULL)
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event windowEvent;

    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT)
            {
                break;
            }
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
    */
}