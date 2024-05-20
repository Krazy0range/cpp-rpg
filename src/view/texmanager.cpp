#include <iostream>
#include <algorithm>
#include <SDL2/SDL_image.h>

#include "texmanager.hpp"
#include "catalogs.hpp"

TextureManager::TextureManager(SDL_Renderer *_renderer)
{
    renderer = _renderer;

    cacheBlockTextures();
    cachePlayerTexture("player.png");
}

TextureManager::~TextureManager()
{
    freeBlockTextureCache();
}

/*
    Load a texture in the res/textures/ folder.
*/
SDL_Texture *TextureManager::loadTexture(const std::string path)
{
    std::string base = SDL_GetBasePath();
    std::string textures = "res/textures/";
    std::string full = base + textures + path;
    SDL_Texture *texture = IMG_LoadTexture(renderer, full.c_str());
    return texture;
}

/*
    Retrieve a cached block texture.
*/
SDL_Texture *TextureManager::getCachedBlockTexture(const BlockItem *blockItem)
{
    SDL_Texture *texture = blockTextureCache[blockItem->textureCacheId];
    return texture;
}

/*
    Retrieve a cached chunk texture.
*/
SDL_Texture *TextureManager::getCachedChunkTexture(const Chunk *chunk)
{
    SDL_Texture *texture = chunkTextureCache[chunk->textureCacheId];
    return texture;
}

/*
    Retrieve the cached player texture.
*/
SDL_Texture *TextureManager::getCachedPlayerTexture()
{
    return playerTexture;
}

/*
    Caches the texture for each block in the game.
*/
void TextureManager::cacheBlockTextures()
{
    cacheBlockTexture(BlockItemCatalog::air);
    cacheBlockTexture(BlockItemCatalog::dirt);
    cacheBlockTexture(BlockItemCatalog::stone);
    cacheBlockTexture(BlockItemCatalog::cobblestone);
    cacheBlockTexture(BlockItemCatalog::stoneBricks);
    cacheBlockTexture(BlockItemCatalog::grass);
    cacheBlockTexture(BlockItemCatalog::grass2);
}

/*
    Cache the texture for a single BlockItem.
*/
void TextureManager::cacheBlockTexture(const BlockItem *blockItem)
{
    SDL_Texture *texture = loadTexture(blockItem->texture);
    blockTextureCache[blockItem->textureCacheId] = texture;
}

/*
    Renders a chunk and caches its texture.
*/
void TextureManager::cacheChunkTexture(const Chunk *chunk)
{
    SDL_Texture *texture; // TODO === === === TODO === === === TODO
    chunkTextureCache[chunk->textureCacheId] = texture;
}

/*
    Cache the player texture
*/
void TextureManager::cachePlayerTexture(const std::string texture)
{
    playerTexture = loadTexture(texture);
}

/*
    Frees all cached block textures.
*/
void TextureManager::freeBlockTextureCache()
{
    for (auto const& [id, texture] : blockTextureCache)
    {
        SDL_DestroyTexture(texture);
    }
}

/*
    Frees all cached chunk textures.
*/
void TextureManager::freeChunkTextureCache()
{
    for (auto const& [id, texture] : chunkTextureCache)
    {
        SDL_DestroyTexture(texture);
    }
}

/*
    Debugs the block texture cache.
*/
void TextureManager::debugBlockTextureCache()
{
    for (auto const& [id, texture] : blockTextureCache)
    {
        std::cout << id << " " << texture << std::endl;
    }
}

/*
    Debugs the chunk texture cache.
*/
void TextureManager::debugChunkTextureCache()
{
    for (auto const& [id, texture] : chunkTextureCache)
    {
        std::cout << id << " " << texture << std::endl;
    }
}