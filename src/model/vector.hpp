#ifndef vector_hpp
#define vector_hpp

struct Vector
{
    int x;
    int y;

    Vector(int x, int y) : x(x), y(y) {};
};

struct Vectorf
{
    float x;
    float y;

    Vectorf(float x, float y) : x(x), y(y) {};
};

#endif