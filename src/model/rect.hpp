#ifndef rect_hpp
#define rect_hpp

#include <string>

struct Rect
{
    int top;
    int left;
    int width;
    int height;

    int getBottom();
    int getRight();
    int getCenterX();
    int getCenterY();
    bool contains(Rect other);
    std::string debug();

    Rect(int top, int left, int width, int height);
    Rect();
};

#endif