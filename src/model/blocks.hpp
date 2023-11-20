#ifndef blocks_hpp
#define blocks_hpp

#include "item.hpp"

class BlockItemCobblestone : public BlockItem 
{
public:
    static const std::string name;
    static const std::string lore;
    static const std::string texture;
    static const ItemRarity rarity;
    static const int stackSize;
    static const int textureCacheId;
};

// TODO FIND A WHOLE DIFFERENT WAY TO DO THIS

#endif