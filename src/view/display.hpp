#ifndef display_hpp
#define display_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "texmanager.hpp"
#include "rect.hpp"
#include "world.hpp"
#include "player.hpp"

class Display
{
    public:
        Display(const Rect windowDimensions, Rect *_camera, World *_world, Player *_player);
        ~Display();
        std::vector<SDL_Event> getEvents();
        void render();
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        TextureManager *textureManager;
        Rect *camera;
        World *world;
        Player *player;
        int frameStart;
        int frameTime;
        int frameDelay = 16;
};

#endif