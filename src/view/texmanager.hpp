#ifndef texmanager_hpp
#define texmanager_hpp

#include <SDL2/SDL.h>
#include <string>
#include <map>

#include "item.hpp"
#include "chunk.hpp"

class TextureManager
{

public:
    TextureManager(SDL_Renderer *_renderer);
    ~TextureManager();
    SDL_Texture *loadTexture(const std::string path);
    SDL_Texture *getCachedBlockTexture(const BlockItem *blockItem);
    SDL_Texture *getCachedChunkTexture(const Chunk *chunk);
    void debugBlockTextureCache();
    void debugChunkTextureCache();

private:
    SDL_Renderer *renderer;
    std::map<int, SDL_Texture *> blockTextureCache;
    std::map<int, SDL_Texture *> chunkTextureCache;
    void cacheBlockTextures();
    void cacheBlockTexture(const BlockItem *blockItem);
    void freeBlockTextureCache();
    void cacheChunkTexture(const Chunk *chunk);
    void freeChunkTextureCache();

};

#endif