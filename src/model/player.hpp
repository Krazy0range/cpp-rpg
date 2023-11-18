#ifndef player_hpp
#define player_hpp

#include <string>

#include "collections.hpp"
#include "entity.hpp"
#include "skills.hpp"
#include "stats.hpp"

class Player: public Entity
{
    public:
        Collections collections;
        Skills skills;
        StatSet stats;
};

#endif