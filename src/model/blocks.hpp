#ifndef blocks_hpp
#define blocks_hpp

#include "items.hpp"

enum BlockDirection
{
    NORTH,
    WEST,
    SOUTH,
    EAST
};

class Block
{
    private:
        int x;
        int y;
        BlockItem block;
        BlockDirection direction;
};

#endif