#include "stats.hpp"

Stat::Stat(
    int level,
    int min,
    int max
) : 
    level(level),
    min(min),
    max(max)
{}

StatSet::StatSet(
    Stat damage,
    Stat critChance,
    Stat critDamage,
    Stat health,
    Stat defense,
    Stat mana
) :
    damage(damage),
    critChance(critChance),
    critDamage(critDamage),
    health(health),
    defense(defense),
    mana(mana)
{}

StatSet::StatSet(
    int damage,
    int critChance,
    int critDamage,
    int health,
    int defense,
    int mana
) :
    damage(damage),
    critChance(critChance),
    critDamage(critDamage),
    health(health),
    defense(defense),
    mana(mana)
{}