#ifndef stat_hpp
#define stat_hpp

class Stats
{
    private:
        StatDamage      damage;
        StatCritDamage  critDamage;
        StatCritChance  critChance;
        StatHealth      health;
        StatDefense     defense;
};

class Stat
{
    private:
        int level;
};

class StatDamage:       public Stat
{

};

class StatCritDamage:   public Stat
{

};

class StatCritChance:   public Stat
{

};

class StatHealth:       public Stat
{

};

class StatDefense:      public Stat
{

};

class StatMana:         public Stat
{

};

#endif