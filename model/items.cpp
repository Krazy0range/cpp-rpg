#include "items.hpp"

Item::Item()
{
    
}

ItemWoodenSword::ItemWoodenSword()
{
    this->stats.damage = 50;
    this->stats.critChance = 25;
    this->stats.critDamage = 25;
}