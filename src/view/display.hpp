#ifndef display_hpp
#define display_hpp

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "texturemanager.hpp"

class Display
{
    public:
        Display();
        ~Display();
        std::vector<SDL_Event> GetEvents();
        void Render();
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        TextureManager *textureManager;
        SDL_Texture *cobble;
};

#endif