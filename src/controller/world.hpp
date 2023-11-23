#ifndef world_hpp
#define world_hpp

#include <array>
#include "block.hpp"

const int worldWidth = 128;
const int worldHeight = 128;

class World
{

public:
    World();
    ~World();
    std::array<std::array<Block *, worldWidth>, worldHeight> *blocks;

private:
    void initializeBlocks();
    void deinitializeBlocks();
    void waveFunctionCollapse(const int x, const int y);
    void setWorldBlock(const int x, const int y, const BlockItem *blockItem);
    bool checkNeighborsFor(const int x, const int y, const BlockItem *blockItem);
    bool checkNeighborsForExclusive(const int x, const int y, const BlockItem *blockItem);
    bool checkNeighborsForExclusivePhysical(const int x, const int y, const BlockItem *blockItem);
    const Block *getWorldBlock(const int x, const int y);
    bool isValidBlockPosition(const int x, const int y);
    const BlockItem *randomBlockItem();
    const BlockItem *randomBlockItemPhysical();
    int randomInt(const int x, const int y);
    bool randomBool();

};

#endif