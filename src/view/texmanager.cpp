#include <iostream>
#include <algorithm>
#include <SDL2/SDL_image.h>

#include "texmanager.hpp"
#include "catalogs.hpp"

TextureManager::TextureManager(SDL_Renderer *_renderer)
{
    renderer = _renderer;

    cacheTextures();
}

TextureManager::~TextureManager()
{
    freeBlockTextureCache();
}

SDL_Texture *TextureManager::loadTexture(const std::string path)
{
    std::string base = SDL_GetBasePath();
    std::string textures = "res/textures/";
    std::string full = base + textures + path;
    SDL_Texture *texture = IMG_LoadTexture(renderer, full.c_str());
    return texture;
}

void TextureManager::cacheTextures()
{
    cacheTexture(BlockItemCatalog::air);
    cacheTexture(BlockItemCatalog::dirt);
    cacheTexture(BlockItemCatalog::cobblestone);
    cacheTexture(BlockItemCatalog::grass);
}

void TextureManager::cacheTexture(const BlockItem *blockItem)
{
    SDL_Texture *texture = loadTexture(blockItem->texture);
    blockTextureCache[blockItem->textureCacheId] = texture;
}

SDL_Texture *TextureManager::getCachedBlockTexture(const BlockItem *blockItem)
{
    SDL_Texture *texture = blockTextureCache[blockItem->textureCacheId];
    return texture;
}

void TextureManager::freeBlockTextureCache()
{
    for (auto const& [id, texture] : blockTextureCache)
    {
        SDL_DestroyTexture(texture);
    }
}

void TextureManager::debugBlockTextureCache()
{
    for (auto const& [id, texture] : blockTextureCache)
    {
        std::cout << id << " " << texture << std::endl;
    }
}