#include <iostream>

#include "quadtree.hpp"
#include "block.hpp"

int main()
{
    Quadtree *quadtree = new Quadtree();
    std::cout << std::endl;

    Block dirt1(0, 0);
    Block dirt2(1, 0);

    quadtree->add(&dirt1);
    quadtree->add(&dirt2);
    quadtree->merge(quadtree->mainNode->children[0].get());
    quadtree->debug();

    std::cout << std::endl;
}