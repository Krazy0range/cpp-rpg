#ifndef items_hpp
#define items_hpp

#include <string>

#include "stats.hpp"

class Item
{
    public:
        StatSet stats;
        std::string texture;
        Item();
};

class ItemWoodenSword: public Item
{
    public:
        ItemWoodenSword();
};

class ItemStone: public Item
{
    public:
        ItemStone();
};

#endif