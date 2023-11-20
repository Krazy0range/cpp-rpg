#ifndef texturemanager_hpp
#define texturemanager_hpp

#include <SDL2/SDL.h>
#include <string>

class TextureManager
{

public:
    TextureManager(SDL_Renderer *renderer);
    SDL_Texture *loadTexture(std::string path);

private:
    SDL_Renderer *renderer;

};

#endif