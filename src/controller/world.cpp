#include <time.h>
#include <iostream>

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
    srand(time(NULL));

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

    std::cout << "Block ***blocks initialized" << std::endl;

    // const int x1 = randomInt(0, worldWidth);
    // const int y1 = randomInt(0, worldHeight);

    // recursedWaveFunctionCollapses = 0;
    // waveFunctionCollapse(x1, y1);

    // std::cout << "we have collapsed" << std::endl;

    // removeAnnoyingDirt();
    // generateStone();
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
    deinitializeBlocks();
    initializeBlocks();
}

/*
    An implementation of part of the Wave Function Collapse algorithm.
*/
void World::waveFunctionCollapse(const int x, const int y)
{
    recursedWaveFunctionCollapses += 1;
    std::cout << "Recursed Wave Function Collapses: " << recursedWaveFunctionCollapses << std::endl;

    if (!isValidBlockPosition(x, y))
    {
        return;
    }

    if (getWorldBlock(x, y)->blockItem != BlockItemCatalog::air)
    {
        return;
    }

    if (checkNeighborsForExclusivePhysical(x, y, BlockItemCatalog::dirt))
    {
        // If only touching dirt,
        // then all blocks are valid
        setWorldBlock(x, y, randomBlockItemPhysical());
    }
    else if (checkNeighborsFor(x, y, BlockItemCatalog::cobblestone) && !checkNeighborsFor(x, y, BlockItemCatalog::grass))
    {
        // If touching cobblestone and not grass,
        // then both cobblestone and dirt are valid.
        // Make cobblestone slightly more likely.
        const int n = randomInt(0, 20);
        if (n >= 7)
            setWorldBlock(x, y, BlockItemCatalog::cobblestone);
        else
            setWorldBlock(x, y, BlockItemCatalog::dirt);
    }
    else if (checkNeighborsFor(x, y, BlockItemCatalog::grass) && !checkNeighborsFor(x, y, BlockItemCatalog::cobblestone))
    {
        // If touching grass and not cobblestone,
        // then both grass and dirt are valid.
        // Make grass slightly more likely.
        const int n = randomInt(0, 20);
        if (n >= 7)
            setWorldBlock(x, y, BlockItemCatalog::grass);
        else
            setWorldBlock(x, y, BlockItemCatalog::dirt);
    }
    else
    {
        // If none of these match,
        // Then do dirt, because it's chill with everything *shrug*
        setWorldBlock(x, y, BlockItemCatalog::dirt);
    }

    waveFunctionCollapse(x + 1, y);
    waveFunctionCollapse(x - 1, y);
    waveFunctionCollapse(x, y + 1);
    waveFunctionCollapse(x, y - 1);
}

/*
    Remove isolated single dirt blocks.
*/
void World::removeAnnoyingDirt()
{
    for (int y = 0; y < worldHeight; y++)
    {
        for (int x = 0; x < worldWidth; x++)
        {
            if (getWorldBlock(x, y)->blockItem == BlockItemCatalog::dirt
             && countNeighborsFor(x, y, BlockItemCatalog::dirt) <= 1)
            {
                if (checkNeighborsFor(x, y, BlockItemCatalog::stone))
                {
                    setWorldBlock(x, y, BlockItemCatalog::stone);
                }
                else if (checkNeighborsFor(x, y, BlockItemCatalog::cobblestone))
                {
                    setWorldBlock(x, y, BlockItemCatalog::cobblestone);
                }
                else if (checkNeighborsFor(x, y, BlockItemCatalog::grass))
                {
                    setWorldBlock(x, y, BlockItemCatalog::grass);
                }
            }
        }
    }
}

/*
    Convert cobblestone to stone.
*/
void World::generateStone()
{
    for (int y = 0; y < worldHeight; y++)
    {
        for (int x = 0; x < worldWidth; x++)
        {
            if ((checkNeighborsFor(x, y, BlockItemCatalog::cobblestone) || checkNeighborsFor(x, y, BlockItemCatalog::stone))
             && !checkNeighborsFor(x, y, BlockItemCatalog::dirt))
            {
                setWorldBlock(x, y, BlockItemCatalog::stone);
            }
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
    Counts how many neighbors a block has of a specific BlockItem.
*/
int World::countNeighborsFor(const int x, const int y, const BlockItem *blockItem)
{
    int neighbors = 0;

    if (getWorldBlock(x - 1, y)->blockItem == blockItem)
        neighbors++;
    if (getWorldBlock(x + 1, y)->blockItem == blockItem)
        neighbors++;
    if (getWorldBlock(x, y - 1)->blockItem == blockItem)
        neighbors++;
    if (getWorldBlock(x, y + 1)->blockItem == blockItem)
        neighbors++;
    if (getWorldBlock(x - 1, y - 1)->blockItem == blockItem)
        neighbors++;
    if (getWorldBlock(x + 1, y + 1)->blockItem == blockItem)
        neighbors++;
    if (getWorldBlock(x + 1, y - 1)->blockItem == blockItem)
        neighbors++;
    if (getWorldBlock(x - 1, y + 1)->blockItem == blockItem)
        neighbors++;
    
    return neighbors;
}

/*
    Checks that a block is touching a specific BlockItem.
*/
bool World::checkNeighborsFor(const int x, const int y, const BlockItem *blockItem)
{
    if (getWorldBlock(x - 1, y)->blockItem == blockItem
     || getWorldBlock(x + 1, y)->blockItem == blockItem
     || getWorldBlock(x, y - 1)->blockItem == blockItem
     || getWorldBlock(x, y + 1)->blockItem == blockItem
     || getWorldBlock(x - 1, y - 1)->blockItem == blockItem
     || getWorldBlock(x + 1, y + 1)->blockItem == blockItem
     || getWorldBlock(x + 1, y - 1)->blockItem == blockItem
     || getWorldBlock(x - 1, y + 1)->blockItem == blockItem)
        return true;
    
    return false;
}

/*
    Checks that a block is only touching a specific BlockItem.
*/
bool World::checkNeighborsForExclusive(const int x, const int y, const BlockItem *blockItem)
{
    if (getWorldBlock(x - 1, y)->blockItem != blockItem
     || getWorldBlock(x + 1, y)->blockItem != blockItem
     || getWorldBlock(x, y - 1)->blockItem != blockItem
     || getWorldBlock(x, y + 1)->blockItem != blockItem
     || getWorldBlock(x - 1, y - 1)->blockItem != blockItem
     || getWorldBlock(x + 1, y + 1)->blockItem != blockItem
     || getWorldBlock(x + 1, y - 1)->blockItem != blockItem
     || getWorldBlock(x - 1, y + 1)->blockItem != blockItem)
        return false;
    
    return true;
}

/*
    Checks that a block is only touching either a specific BlockItem or air.
*/
bool World::checkNeighborsForExclusivePhysical(const int x, const int y, const BlockItem *blockItem)
{
    if ((getWorldBlock(x - 1, y)->blockItem != blockItem && getWorldBlock(x - 1, y)->blockItem != BlockItemCatalog::air)
     || (getWorldBlock(x + 1, y)->blockItem != blockItem && getWorldBlock(x + 1, y)->blockItem != BlockItemCatalog::air)
     || (getWorldBlock(x, y - 1)->blockItem != blockItem && getWorldBlock(x, y - 1)->blockItem != BlockItemCatalog::air)
     || (getWorldBlock(x, y + 1)->blockItem != blockItem && getWorldBlock(x, y + 1)->blockItem != BlockItemCatalog::air)
     || (getWorldBlock(x - 1, y - 1)->blockItem != blockItem && getWorldBlock(x - 1, y - 1)->blockItem != BlockItemCatalog::air)
     || (getWorldBlock(x + 1, y + 1)->blockItem != blockItem && getWorldBlock(x + 1, y + 1)->blockItem != BlockItemCatalog::air)
     || (getWorldBlock(x + 1, y - 1)->blockItem != blockItem && getWorldBlock(x + 1, y - 1)->blockItem != BlockItemCatalog::air)
     || (getWorldBlock(x - 1, y + 1)->blockItem != blockItem && getWorldBlock(x - 1, y + 1)->blockItem != BlockItemCatalog::air))
        return false;
    
    return true;
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