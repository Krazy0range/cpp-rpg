#include <time.h>
#include <iostream>

#include "FastNoiseLite.h"

#include "world.hpp"
#include "catalogs.hpp"

World::World()
{
    initializeBlocks();
    // initializeChunks();
}

World::~World()
{
    deinitializeBlocks();
    // deinitializeChunks();
}

/*
    Initialize blocks.
*/
void World::initializeBlocks()
{
    invalidBlock = new Block(-1, -1, BlockItemCatalog::air);
    
    // blocks = new std::array<std::array<Block *, worldWidth>, worldHeight>();
    blocks = new Block **[worldHeight];

    for (int y = 0; y < worldHeight; y++)
    {
        blocks[y] = new Block *[worldWidth];

        for (int x = 0; x < worldWidth; x++)
        {
            blocks[y][x] = new Block(x, y, BlockItemCatalog::stone);
        }
    }

    generateBlocks();
}

/*
    Deinitialize blocks.
*/
void World::deinitializeBlocks()
{
    delete invalidBlock;

    for (int y = 0; y < worldHeight; y++)
    {
        for (int x = 0; x < worldWidth; x++)
        {
            delete blocks[y][x];
        }

        delete[] blocks[y];
    }

    delete[] blocks;
}

/*
    Reinitialize blocks.
*/
void World::reinitializeBlocks()
{
    std::cout << "\x1b[2mRegenerating world...\x1b[0m" << std::endl;
    generateBlocks();
}

/*
    Generate blocks using noise.
*/
void World::generateBlocks()
{
    srand(time(NULL));
    const int xOffset = rand();
    const int yOffset = rand();
    const int xOffset2 = rand();
    const int yOffset2 = rand();

    FastNoiseLite noise;
    noise.SetNoiseType(FastNoiseLite::NoiseType_Perlin);

    const float islandRadius = 12;
    const float islandNoiseScale = 10;
    const float grassNoiseScale = 30;

    for (int y = 0; y < worldHeight; y++)
    {
        for (int x = 0; x < worldWidth; x++)
        {
            const float xDistance = abs(x - (worldWidth / 2));
            const float yDistance = abs(y - (worldHeight / 2));
            const float distance = sqrt(xDistance * xDistance + yDistance * yDistance);
            const float slope = 1 - (distance / islandRadius);
            const float islandNoiseValue = noise.GetNoise((x + xOffset) * islandNoiseScale, (y + yOffset) * islandNoiseScale) + slope * 5;
            const float grassNoiseValue = noise.GetNoise((x + xOffset2) * grassNoiseScale, (y + yOffset2) * grassNoiseScale);

            const BlockItem *blockItem;

            if (islandNoiseValue < 0)
            {
                blockItem = BlockItemCatalog::air;
            }
            else if (islandNoiseValue > 1)
            {
                if (grassNoiseValue > 0.1)
                {
                    blockItem = BlockItemCatalog::grass;
                }
                else
                {
                    blockItem = BlockItemCatalog::grass2;
                }
            }
            else if (grassNoiseValue > 0.1)
            {
                blockItem = BlockItemCatalog::dirt;
            }
            else
            {
                blockItem = BlockItemCatalog::cobblestone;
            }

            setWorldBlock(x, y, blockItem);
        }
    }
}

/*
    Sets a specific block.
*/
void World::setWorldBlock(const int x, const int y, const BlockItem *blockItem)
{
    // (*blocks)[y][x]->blockItem = blockItem;
    blocks[y][x]->blockItem = blockItem;
}

/*
    Retrieve a Block at a specific location.
*/
const Block *World::getWorldBlock(const int x, const int y)
{
    if (isValidBlockPosition(x, y))
    {
        // return (*blocks)[y][x];
        return blocks[y][x];
    }
    else
    {
        return invalidBlock;
    }
}

/*
    Check that a position is within world bounds.
*/
bool World::isValidBlockPosition(const int x, const int y)
{
    if (x < 0 || x >= worldWidth)
        return false;
    
    if (y < 0 || y >= worldHeight)
        return false;
    
    return true;
}

/*
    Return a random BlockItem, including air.
*/
const BlockItem *World::randomBlockItem()
{
    const BlockItem *blockItem;

    switch (rand() % 4)
    {
        case 0:
            blockItem = BlockItemCatalog::dirt;
            break;
        case 1:
            blockItem = BlockItemCatalog::cobblestone;
            break;
        case 2:
            blockItem = BlockItemCatalog::grass;
            break;
        case 3:
            blockItem = BlockItemCatalog::air;
            break;
        default:
            blockItem = BlockItemCatalog::air;
            break;
    }

    return blockItem;
}

/*
    Return a random BlockItem, excluding air.
*/
const BlockItem *World::randomBlockItemPhysical()
{
    const BlockItem *blockItem;

    switch (rand() % 3)
    {
        case 0:
            blockItem = BlockItemCatalog::dirt;
            break;
        case 1:
            blockItem = BlockItemCatalog::cobblestone;
            break;
        case 2:
            blockItem = BlockItemCatalog::grass;
            break;
        default:
            blockItem = BlockItemCatalog::air;
            break;
    }

    return blockItem;
}

/*
    Return a random integer, lower bound inclusive, upper exclusive.
*/
int World::randomInt(const int x, const int y)
{
    return (rand() % (y - x)) + x;
}

/*
    Return a random boolean.
*/
bool World::randomBool()
{
    return rand() % 2 == 0;
}

/*
    Initialize chunks from the initialized blocks.
*/
// void World::initializeChunks()
// {
//     chunks = new std::array<std::array<Chunk *, worldChunkWidth>, worldChunkHeight>;

//     int chunkTextureCacheIdTracker = 0;

//     for (int x = 0; x < worldWidth; x += chunkSize)
//     {
//         for (int y = 0; y < worldHeight; y += chunkSize)
//         {
//             std::array<std::array<Block *, chunkSize>, chunkSize> chunkBlocks;
//             chunkBlocks = copyChunkBlocks(x, y);
//             (*chunks)[y/chunkSize][x/chunkSize] = new Chunk(Rect(x, y, chunkSize, chunkSize), chunkTextureCacheIdTracker);
//             chunkTextureCacheIdTracker++;

//             // DEBUG
//             std::cout << chunkBlocks[0][0]->blockItem->texture << std::endl;
//             std::cout << chunkBlocks[0][1]->blockItem->texture << std::endl;
//             std::cout << chunkBlocks[0][2]->blockItem->texture << std::endl;

//             break;
//         }
//         break;
//     }

// }

// /*
//     Deinitialize chunks.
// */
// void World::deinitializeChunks()
// {
//     for (int x = 0; x < worldChunkWidth; x++)
//     {
//         for (int y = 0; y < worldChunkHeight; y++)
//         {
//             delete (*chunks)[y][x];
//             (*chunks)[y][x] = NULL;
//         }
//     }

//     delete chunks;
//     chunks = NULL;
// }

// /*
//     Copy a 2D rectangle from the blocks array.
// */
// std::array<std::array<Block *, chunkSize>, chunkSize> World::copyChunkBlocks(const int x, const int y)
// {
//     std::array<std::array<Block *, chunkSize>, chunkSize> chunkBlocks;
//     for (int _x = 0; _x < chunkSize; _x++)
//     {
//         for (int _y = 0; _y < chunkSize; _y++)
//         {
//             chunkBlocks[_x][_y] = (*blocks)[_y+y][_x+x];
//         }
//     }
//     return chunkBlocks;
// }