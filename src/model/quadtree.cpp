#include <iostream>
#include <cmath>

#include "quadtree.hpp"

void Node::setBounds(int top, int left)
{
    bounds = Rect(top, left, pow(2, height), pow(2, height));
}

Quadtree::Quadtree()
{
    mainNode = std::make_unique<Node>();
    mainNode->height = 6;
    mainNode->setBounds(0, 0);
}

void Quadtree::add(Block *block)
{
    add(block, mainNode.get());
}

void Quadtree::remove(Block *block)
{
    remove(block, mainNode.get());
}

bool Quadtree::add(Block *block, Node *node)
{
    // std::cout << "Okay, so we're dealing with:";
    // std::cout << "\ta block at: " << block->rect.debug();
    // std::cout << "\ta node at: " << node->bounds.debug();
    // std::cout << std::endl;

    if (node->bounds.contains(block->rect))
    {
        // std::cout << "we are within bounds!" << std::endl;
        if (node->height != 0)
        {
            if (isLeaf(node))
            {
                split(node);
            }

            for (auto& child : node->children)
            {
                if (add(block, child.get()))
                    break;
            }
        }
        else
        {
            std::cout << "added block at " << block->rect.top << " " << block->rect.left << std::endl;
            node->block = block;

            return true;
        }
    }
    else
    {
        // std::cout << "we are without bounds!" << std::endl;
        return false;
    }

    return true;
}

void Quadtree::split(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    if (isLeaf(node) && node->height != 0)
    {
        int i = 0;
        for (auto& child : node->children)
        {
            child = std::make_unique<Node>();
            child->height = node->height - 1;
            
            switch (i)
            {
            case 0:
                child->setBounds(node->bounds.top, node->bounds.left);
                break;
            case 1:
                child->setBounds(node->bounds.getCenterX(), node->bounds.left);
                break;
            case 2:
                child->setBounds(node->bounds.top, node->bounds.getCenterY());
                break;
            case 3:
                child->setBounds(node->bounds.getCenterX(), node->bounds.getCenterY());
                break;
            default:
                std::cout << "Invalid case for \"i\" in Quadtree::split(Node *node): " << i << std::endl;
                break;
            }

            i++;
        }
    }
}

bool Quadtree::isLeaf(Node *node)
{
    bool leaf = node->children[0] == nullptr;
    return leaf;
}

void Quadtree::debug()
{
    std::cout << "\x1b[2mQUADTREE DEBUG\x1b[0m" << std::endl;
    _debug(mainNode.get(), 0);
    std::cout << std::endl;
}

void Quadtree::_debug(Node *node, int depth)
{
    if (node == nullptr)
        return;

    std::cout << std::string(depth*4, ' ') << "Node h" << node->height;
    std::cout << " wh" << node->bounds.width;
    if (node->block != std::experimental::nullopt)
        std::cout << " block";
    std::cout << std::endl;

    for (auto& child : node->children)
    {
        _debug(child.get(), depth+1);
    }
}