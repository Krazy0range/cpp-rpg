#include <iostream>

#include "quadtree.hpp"
#include "block.hpp"

int main()
{
    Quadtree *quadtree = new Quadtree();
    std::cout << std::endl;

    Block dirt1(0, 0);
    Block dirt2(16, 0);

    quadtree->add(&dirt1);
    quadtree->add(&dirt2);
    quadtree->debug();
    quadtree->remove(&dirt1);
    std::cout << std::endl;
    quadtree->debug();
    quadtree->remove(&dirt2);
    std::cout << std::endl;
    quadtree->debug();

    std::cout << std::endl;

    delete quadtree;
}