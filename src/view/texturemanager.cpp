#include "texturemanager.hpp"

TextureManager::TextureManager(SDL_Renderer *renderer)
{
    renderer = renderer;
}

SDL_Texture *TextureManager::loadTexture(std::string path)
{
    SDL_Surface *surface = SDL_LoadBMP(("res/textures/" + path).c_str());
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    return texture;
}