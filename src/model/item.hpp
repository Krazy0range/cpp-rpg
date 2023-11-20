#ifndef item_hpp
#define item_hpp

#include <string>

#include "stats.hpp"

enum ItemRarity
{
    COMMON,
    UNCOMMON,
    RARE,
    EPIC,
    LEGENDARY,
    MYTHICAL,
    DIVINE
};

class Item
{
    public:
        static const std::string name;
        static const std::string lore;
        static const std::string texture;
        static const ItemRarity rarity;
};

class LootItem: public Item
{
    public:
        static const StatSet stats;
};

class MaterialItem: public Item
{
    public:
        static const int stackSize;
};

class BlockItem: public MaterialItem
{
    public:
        static const int textureCacheId;
};

#endif