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
        StatSet() = default;
        StatSet(
            Stat damage,
            Stat critChance,
            Stat critDamage,
            Stat health,
            Stat defense,
            Stat mana
        );
        StatSet(
            int damage,
            int critChance,
            int critDamage,
            int health,
            int defense,
            int mana
        );
};

#endif