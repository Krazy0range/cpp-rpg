#include <iostream>

#include "main.hpp"

// #include "vld.h"

int main(int argv, char** args)
{
    Main *main = new Main();
 
    main->loop();

    delete main;

    return 0;
}