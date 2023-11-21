#ifndef stat_hpp
#define stat_hpp

class Stat
{

public:
    Stat() = default;
    Stat(
        int level,
        int min,
        int max
    ) : 
        level(level),
        min(min),
        max(max)
    {};
    Stat(
        int level
    ) :
        level(level),
        min(0),
        max(100)
    {};
    int level;
    int min;
    int max;
    
};

class StatSet
{

public:
    StatSet() = default;
    StatSet(
        Stat damage,
        Stat critChance,
        Stat critDamage,
        Stat health,
        Stat defense,
        Stat mana,
        Stat speed,
        Stat attackSpeed,
        Stat miningSpeed,
        Stat farmingSpeed,
        Stat fishingSpeed,
        Stat luck,
        Stat fortune,
        Stat wisdom,
        Stat reach,
        Stat vision
    ) :
        damage(damage),
        critChance(critChance),
        critDamage(critDamage),
        health(health),
        defense(defense),
        mana(mana),
        speed(speed),
        attackSpeed(attackSpeed),
        miningSpeed(miningSpeed),
        farmingSpeed(farmingSpeed),
        fishingSpeed(fishingSpeed),
        luck(luck),
        fortune(fortune),
        wisdom(wisdom),
        reach(reach),
        vision(vision)
    {};
    StatSet(
        int damage,
        int critChance,
        int critDamage,
        int health,
        int defense,
        int mana,
        int speed,
        int attackSpeed,
        int miningSpeed,
        int farmingSpeed,
        int fishingSpeed,
        int luck,
        int fortune,
        int wisdom,
        int reach,
        int vision
    ) :
        damage(damage),
        critChance(critChance),
        critDamage(critDamage),
        health(health),
        defense(defense),
        mana(mana),
        speed(speed),
        attackSpeed(attackSpeed),
        miningSpeed(miningSpeed),
        farmingSpeed(farmingSpeed),
        fishingSpeed(fishingSpeed),
        luck(luck),
        fortune(fortune),
        wisdom(wisdom),
        reach(reach),
        vision(vision)
    {};
    Stat damage;
    Stat critChance;
    Stat critDamage;
    Stat health;
    Stat defense;
    Stat mana;
    Stat speed;
    Stat attackSpeed;
    Stat miningSpeed;
    Stat farmingSpeed;
    Stat fishingSpeed;
    Stat luck;
    Stat fortune;
    Stat wisdom;
    Stat reach;
    Stat vision;

};

#endif