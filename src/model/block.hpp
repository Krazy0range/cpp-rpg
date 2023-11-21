#ifndef block_hpp
#define block_hpp

#include "item.hpp"
#include "rect.hpp"

struct Block
{
    Block(
        const int x,
        const int y,
        const BlockItem block
    ) :
        rect(x, y, 1, 1),
        block(block)
    {};
    Rect rect;
    BlockItem block;
};

#endif