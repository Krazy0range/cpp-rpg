#ifndef player_hpp
#define player_hpp

#include <string>

#include "lingual.hpp"
#include "rect.hpp"
#include "stats.hpp"

class Player
{
    public:
        Player(
            LingualString name,
            StatSet stats,
            Rect rect
        ) :
            name(name),
            stats(stats),
            rect(rect)
        {};

        const LingualString name;
        StatSet stats;
        Rect rect;
};

#endif