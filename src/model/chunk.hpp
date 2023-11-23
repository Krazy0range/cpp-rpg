#ifndef chunk_hpp
#define chunk_hpp

#include <array>

#include "block.hpp"
#include "rect.hpp"

const int chunkSize = 16;

struct Chunk
{
    Chunk(
        Rect rect,
        int textureCacheId
    ) :
        rect(rect),
        textureCacheId(textureCacheId)
    {};

    std::array<std::array<Block *, chunkSize>, chunkSize> blocks;
    Rect rect;
    int textureCacheId;
};

#endif