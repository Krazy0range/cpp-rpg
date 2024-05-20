#ifndef player_hpp
#define player_hpp

#include <string>

#include "lingual.hpp"
#include "vector.hpp"
#include "stats.hpp"

class Player
{
    public:
        Player(
            LingualString name,
            StatSet stats,
            Vectorf position
        ) :
            name(name),
            stats(stats),
            position(position)
        {};

        const LingualString name;
        StatSet stats;
        Vectorf position;
};

#endif