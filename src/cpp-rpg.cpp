#include <iostream>

#include "controller/main.hpp"

int main(int argv, char** args)
{
    Main *main = new Main();
 
    main->loop();

    delete main;

    return 0;
}