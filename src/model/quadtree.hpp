#ifndef quadtree_hpp
#define quadtree_hpp

#include <array>
#include <memory>
#include <vector>
#include <experimental/optional> 

#include "block.hpp"
#include "rect.hpp"

struct Node
{
    std::array<std::unique_ptr<Node>, 4> children;
    std::experimental::optional<Block *> block;
    Rect bounds;
    int height;

    void setBounds(int top, int left);
};

class Quadtree
{

public:
    
    Quadtree();
    void debug();
    void add(Block *block);
    void remove(Block *block);

private:

    std::unique_ptr<Node> mainNode;
    bool isLeaf(Node *node);
    void _debug(Node *node, int depth);
    bool add(Block *block, Node *node);
    bool remove(Block *block, Node *node);
    void split(Node *node);
    void merge(Node *node);

};

#endif