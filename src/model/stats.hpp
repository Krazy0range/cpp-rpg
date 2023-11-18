#ifndef stat_hpp
#define stat_hpp

class Stat
{
    public:
        int level = 0;
        int min = 0;
        int max = 100;
        Stat() = default;
        Stat(
            int level,
            int min = 0,
            int max = 100
        );
};

class StatSet
{
    public:
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
        );
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
        );
};

#endif