#include <time.h>
#include <iostream>

#include "world.hpp"
#include "catalogs.hpp"

World::World()
{
    initializeBlocks();
}

World::~World()
{
    deinitializeBlocks();
}

void World::initializeBlocks()
{
    srand(time(NULL));
    
    blocks = new std::array<std::array<Block *, worldWidth>, worldHeight>();
    std::cout << sizeof(*blocks) << std::endl;

    for (int y = 0; y < worldHeight; y++)
    {
        for (int x = 0; x < worldWidth; x++)
        {
            (*blocks)[y][x] = new Block(x, y, BlockItemCatalog::air);
        }
    }

    const int x1 = randomInt(0, worldWidth);
    const int y1 = randomInt(0, worldHeight);

    waveFunctionCollapse(x1, y1);
}

void World::deinitializeBlocks()
{
    for (int x = 0; x < worldWidth; x++)
    {
        for (int y = 0; y < worldHeight; y++)
        {
            delete (*blocks)[x][y];
            (*blocks)[x][y] = NULL;
        }
    }
}

/*
    World::waveFunctionCollapse
        An implementation of part of the Wave Function Collapse algorithm
*/
void World::waveFunctionCollapse(const int x, const int y)
{
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
        const int n = randomInt(0, 3);
        if (n >= 1) // 2/3 chance
            setWorldBlock(x, y, BlockItemCatalog::cobblestone);
        else
            setWorldBlock(x, y, BlockItemCatalog::dirt);
    }
    else if (checkNeighborsFor(x, y, BlockItemCatalog::grass) && !checkNeighborsFor(x, y, BlockItemCatalog::cobblestone))
    {
        // If touching grass and not cobblestone,
        // then both grass and dirt are valid.
        // Make grass slightly more likely.
        const int n = randomInt(0, 3);
        if (n >= 1) // 2/3 chance
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

    waveFunctionCollapse(x - 1, y);
    waveFunctionCollapse(x + 1, y);
    waveFunctionCollapse(x, y - 1);
    waveFunctionCollapse(x, y + 1);
}

/*
    World::setWorldBlock
        Sets a specific block
*/
void World::setWorldBlock(const int x, const int y, const BlockItem *blockItem)
{
    (*blocks)[y][x]->blockItem = blockItem;
}

/*
    World::checkNeighborsFor
        Checks that a block is touching a specific BlockItem
*/
bool World::checkNeighborsFor(const int x, const int y, const BlockItem *blockItem)
{
    if (getWorldBlock(x - 1, y)->blockItem == blockItem
     || getWorldBlock(x + 1, y)->blockItem == blockItem
     || getWorldBlock(x, y - 1)->blockItem == blockItem
     || getWorldBlock(x, y + 1)->blockItem == blockItem)
        return true;
    
    return false;
}

/*
    World::checkNeighborsForExclusive
        Checks that a block is only touching a specific BlockItem
*/
bool World::checkNeighborsForExclusive(const int x, const int y, const BlockItem *blockItem)
{
    if (getWorldBlock(x - 1, y)->blockItem != blockItem
     || getWorldBlock(x + 1, y)->blockItem != blockItem
     || getWorldBlock(x, y - 1)->blockItem != blockItem
     || getWorldBlock(x, y + 1)->blockItem != blockItem)
        return false;
    
    return true;
}

/*
    World::checkNeighborsForExclusivePhysical
        Checks that a block is only touching either a specific BlockItem or air
*/
bool World::checkNeighborsForExclusivePhysical(const int x, const int y, const BlockItem *blockItem)
{
    if ((getWorldBlock(x - 1, y)->blockItem != blockItem && getWorldBlock(x - 1, y)->blockItem != BlockItemCatalog::air)
     || (getWorldBlock(x + 1, y)->blockItem != blockItem && getWorldBlock(x + 1, y)->blockItem != BlockItemCatalog::air)
     || (getWorldBlock(x, y - 1)->blockItem != blockItem && getWorldBlock(x, y - 1)->blockItem != BlockItemCatalog::air)
     || (getWorldBlock(x, y + 1)->blockItem != blockItem && getWorldBlock(x, y + 1)->blockItem != BlockItemCatalog::air))
        return false;
    
    return true;
}

/*
    World::getWorldBlock
        Retrieve a Block at a specific location
*/
const Block *World::getWorldBlock(const int x, const int y)
{
    if (isValidBlockPosition(x, y))
    {
        return (*blocks)[y][x];
    }
    else
    {
        const Block *invalid = new Block(x, y, BlockItemCatalog::air);
        return invalid;
    }
}

/*
    World::isValidBlockPosition
        Check that a position is within world bounds
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
    World::randomBlockItem
        Return a random BlockItem, including air
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
    World::randomBlockItemPhysical
        Return a random BlockItem, excluding air
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
    World::randomInt
        Return a random integer, lower bound inclusive, upper exclusive
*/
int World::randomInt(const int x, const int y)
{
    return (rand() % (y - x)) + x;
}

/*
    World::randomBool
        Return a random boolean
*/
bool World::randomBool()
{
    return rand() % 2 == 0;
}

