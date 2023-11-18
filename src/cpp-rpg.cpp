#include <iostream>

#include "controller/main.hpp"

int main(int argv, char** args)
{
    Main *main = new Main();
 
    main->Loop();

    delete main;

    return 0;
}