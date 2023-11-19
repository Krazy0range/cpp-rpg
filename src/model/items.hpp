#ifndef items_hpp
#define items_hpp

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

enum BlockDirection
{
    NORTH,
    WEST,
    SOUTH,
    EAST
};

class Item
{
    public:
        std::string name;
        std::string lore;
        std::string texture;
        ItemRarity rarity;
};

class LootItem: public Item
{
    public:
        StatSet stats;
};

class MaterialItem: public Item
{
    public:
        int stackSize;
};

class BlockItem: public MaterialItem
{
    public:
        // Example settings, likely to change
        BlockDirection direction;
        bool waterLogged;
        bool hydrated;
};

#endif