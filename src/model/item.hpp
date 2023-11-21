#ifndef item_hpp
#define item_hpp

#include <string>

#include "stats.hpp"
#include "lingual.hpp"

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
    Item(
        const LingualString name,
        const LingualString lore,
        const std::string texture,
        const ItemRarity rarity
    ) :
        name(name),
        lore(lore),
        texture(texture),
        rarity(rarity)
    {};
    const LingualString name;
    const LingualString lore;
    const std::string texture;
    const ItemRarity rarity;

};

class LootItem: public Item
{

public:
    LootItem(
        const LingualString name,
        const LingualString lore,
        const std::string texture,
        const ItemRarity rarity,
        const StatSet stats
    ) :
        Item(name, lore, texture, rarity),
        stats(stats)
    {};
    const StatSet stats;

};

class MaterialItem: public Item
{

public:
    MaterialItem(
        const LingualString name,
        const LingualString lore,
        const std::string texture,
        const ItemRarity rarity,
        const int stackSize
    ) :
        Item(name, lore, texture, rarity),
        stackSize(stackSize)
    {};
    const int stackSize;
    static const int MaxStackSize = 99;

};

class BlockItem: public MaterialItem
{

public:
    BlockItem(
        const LingualString name,
        const LingualString lore,
        const std::string texture,
        const ItemRarity rarity,
        const int stackSize,
        const int textureCacheId
    ) :
        MaterialItem(name, lore, texture, rarity, stackSize),
        textureCacheId(textureCacheId)
    {};
    const int textureCacheId;

};

#endif