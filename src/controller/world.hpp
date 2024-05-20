#ifndef world_hpp
#define world_hpp

#include <array>
#include "block.hpp"
#include "chunk.hpp"

const int worldWidth = 50;
const int worldHeight = 50;
const int worldChunkWidth = worldWidth / chunkSize;
const int worldChunkHeight = worldHeight / chunkSize;

class World
{

public:
    World();
    ~World();
    // std::array<std::array<Block *, worldWidth>, worldHeight> *blocks;
    Block ***blocks;
    std::array<std::array<Chunk *, worldChunkWidth>, worldChunkHeight> *chunks;
    void reinitializeBlocks();

private:
/*
    Blocks
*/
    const Block *invalidBlock;
    void initializeBlocks();
    void deinitializeBlocks();
    void generateBlocks();
    void setWorldBlock(const int x, const int y, const BlockItem *blockItem);
    const Block *getWorldBlock(const int x, const int y);
    bool isValidBlockPosition(const int x, const int y);
    const BlockItem *randomBlockItem();
    const BlockItem *randomBlockItemPhysical();
    int randomInt(const int x, const int y);
    bool randomBool();
// /*
//     Chunks
// */
//     void initializeChunks();
//     void deinitializeChunks();
//     std::array<std::array<Block *, chunkSize>, chunkSize> copyChunkBlocks(const int x, const int y);
};

#endif