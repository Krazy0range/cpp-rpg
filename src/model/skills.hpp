#ifndef playerskill_hpp
#define playerskill_hpp

#include <vector>

class Skill
{
    private:
        int exp;
        int level;
        std::vector<int> levels;
};

class SkillCombat:    public Skill
{

};

class SkillMining:    public Skill
{

};

class SkillFarming:   public Skill
{

};

class SkillFishing:   public Skill
{

};

class SkillMagic:     public Skill
{

};

class SkillTaming:    public Skill
{

};

class Skills
{
    private:
        SkillCombat   combat;
        SkillMining   mining;
        SkillFishing  fishing;
        SkillFarming  farming;
        SkillMagic    magic;
        SkillTaming   taming;
};

#endif