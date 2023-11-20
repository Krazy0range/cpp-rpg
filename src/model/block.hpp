#ifndef blocks_hpp
#define blocks_hpp

#include "items.hpp"
#include "rect.hpp"

enum BlockDirection
{
    NORTH,
    WEST,
    SOUTH,
    EAST
};

struct Block
{
    Block(int x, int y);
    Rect rect;
    BlockItem block;
    BlockDirection direction;
};

#endif