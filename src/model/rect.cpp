#include <sstream>
#include "rect.hpp"

Rect::Rect(int t, int l, int w, int h)
{
    top = t;
    left = l;
    width = w;
    height = h;
}

Rect::Rect()
{
    top = 0;
    left = 0;
    width = 0;
    height = 0;
}

int Rect::getBottom()
{
    return top + height;
}

int Rect::getRight()
{
    return left + width;
}

int Rect::getCenterX()
{
    return left + (width / 2);
}

int Rect::getCenterY()
{
    return top + (height / 2);
}

bool Rect::contains(Rect other)
{
    return top <= other.top
        && left <= other.left
        && getBottom() >= other.getBottom()
        && getRight() >= other.getRight();
}

std::string Rect::debug()
{
    std::stringstream debug;
    debug << "" << top << " " << left << " " << width << " " << height;
    return debug.str();
}

bool Rect::operator==(Rect &other)
{
    return top == other.top
        && left == other.left
        && width == other.width
        && height == other.height;
}