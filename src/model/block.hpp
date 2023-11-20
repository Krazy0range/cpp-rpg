#ifndef block_hpp
#define block_hpp

#include "item.hpp"
#include "rect.hpp"

struct Block
{
    Block(int x, int y);
    Rect rect;
    BlockItem block;
};

#endif