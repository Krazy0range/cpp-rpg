#ifndef texmanager_hpp
#define texmanager_hpp

#include <SDL2/SDL.h>
#include <string>
#include <map>

#include "item.hpp"

class TextureManager
{

public:
    TextureManager(SDL_Renderer *_renderer);
    ~TextureManager();
    SDL_Texture *loadTexture(const std::string path);
    SDL_Texture *getCachedBlockTexture(const BlockItem *blockItem);
    void debugBlockTextureCache();

private:
    SDL_Renderer *renderer;
    std::map<int, SDL_Texture *> blockTextureCache;
    void cacheTextures();
    void cacheTexture(const BlockItem *blockItem);
    void freeBlockTextureCache();

};

#endif