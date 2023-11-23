#include <iostream>

#include "display.hpp"
#include "catalogs.hpp"

Display::Display(const Rect windowDimensions, Rect *_camera, World *_world)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    
    window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowDimensions.width, windowDimensions.height, SDL_WINDOW_ALLOW_HIGHDPI);

    if (window == NULL)
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL)
    {
        std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
        return;
    }

    textureManager = new TextureManager(renderer);

    camera = _camera;
    world = _world;
}

Display::~Display()
{
    delete textureManager;
    textureManager = NULL;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Display::render()
{
    frameStart = SDL_GetTicks64();

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    int mouseX;
    int mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);

    // SDL_Rect rect;
    // rect.x = 0;
    // rect.y = 0;
    // rect.w = mouseX;
    // rect.h = mouseY;
    // SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // SDL_RenderFillRect(renderer, &rect);

    const int blockSize = 16;

    SDL_Texture *texture = textureManager->getCachedBlockTexture(BlockItemCatalog::dirt);
    SDL_Rect blockRect;
    blockRect.x = 0;
    blockRect.y = 0;
    blockRect.w = blockSize;
    blockRect.h = blockSize;
    
    // for (int x = 0; x < 10; x++)
    // {
    //     for (int y = 0; y < 10; y++)
    //     {
    //         blockRect.x = x * 64;
    //         blockRect.y = y * 64;
    //         SDL_RenderCopy(renderer, block, NULL, &blockRect);
    //     }
    // }

    for (auto& row : *(world->blocks))
    {
        for (auto& block : row)
        {
            blockRect.x = block->rect.left * blockSize - camera->left;
            blockRect.y = block->rect.top * blockSize - camera->top;
            texture = textureManager->getCachedBlockTexture(block->blockItem);
            SDL_RenderCopy(renderer, texture, NULL, &blockRect);
        }
    }

    SDL_RenderPresent(renderer);

    frameTime = SDL_GetTicks64() - frameStart;
    if (frameDelay > frameTime)
    {
        SDL_Delay(frameDelay - frameTime);
    }
}


std::vector<SDL_Event> Display::getEvents()
{
    std::vector<SDL_Event> events;

    SDL_Event windowEvent;
    while (SDL_PollEvent(&windowEvent))
    {
        events.push_back(windowEvent);
    }

    return events;
}