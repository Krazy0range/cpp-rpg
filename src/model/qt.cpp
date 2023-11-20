#include <iostream>

#include "quadtree.hpp"
#include "block.hpp"

int main()
{
    Quadtree *quadtree = new Quadtree();
    std::cout << std::endl;

    Block dirt1(0, 0);
    Block dirt2(16, 0);
    Block dirt3(32, 32);


    quadtree->add(&dirt1);
    std::cout << "add dirt1" << std::endl;
    quadtree->add(&dirt2);
    std::cout << "add dirt2" << std::endl;

    quadtree->remove(&dirt2);
    std::cout << "remove dirt2" << std::endl;

    Node *node = quadtree->query(&dirt2);
    if (node) 
    {
        std::cout << node->debug() << std::endl;
    }
    else
    {
        std::cout << "dirt2 not found" << std::endl;
    }

    quadtree->debug();

    std::cout << std::endl;

    delete quadtree;
}