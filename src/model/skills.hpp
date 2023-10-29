#ifndef playerskill_hpp
#define playerskill_hpp

#include <vector>

class PlayerSkills
{
    private:
        PlayerSkillCombat   combat;
        PlayerSkillMining   mining;
        PlayerSkillFishing  fishing;
        PlayerSkillFarming  farming;
        PlayerSkillMagic    magic;
        PlayerSkillTaming   taming;
};

class PlayerSkill
{
    private:
        int exp;
        int level;
        std::vector<int> levels;
};

class PlayerSkillCombat:    public PlayerSkill
{

};

class PlayerSkillMining:    public PlayerSkill
{

};

class PlayerSkillFarming:   public PlayerSkill
{

};

class PlayerSkillFishing:   public PlayerSkill
{

};

class PlayerSkillMagic:     public PlayerSkill
{

};

class PlayerSkillTaming:    public PlayerSkill
{

};

#endif