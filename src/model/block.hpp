#ifndef block_hpp
#define block_hpp

#include "item.hpp"
#include "rect.hpp"

struct Block
{
    Block(
        const int x,
        const int y,
        const BlockItem *blockItem
    ) :
        rect(x, y, 1, 1),
        blockItem(blockItem)
    {};
    
    Rect rect;
    const BlockItem *blockItem;
};

#endif