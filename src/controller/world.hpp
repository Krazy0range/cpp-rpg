#ifndef world_hpp
#define world_hpp

#include <vector>

#include "entity.hpp"

class World
{
    public:
        World();
    private:
        std::vector<Entity> entities;
};

#endif