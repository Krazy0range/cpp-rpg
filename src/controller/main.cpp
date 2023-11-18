#include <iostream>

#include "main.hpp"

Main::Main()
{
    std::cout << std::endl;

    InitModel();
    InitView();
    InitController();

    std::cout << "Initialization completed" << std::endl;
}

Main::~Main()
{
    DeinitModel();
    DeinitView();
    DeinitController();

    std::cout << "Deinitialization completed" << std::endl;
    std::cout << std::endl;
}

void Main::Loop()
{
    std::cout << "Main Loop started" << std::endl;

    bool done = false;
    while (!done)
    {
        std::vector<Event> events = display->GetEvents();
        for (Event event : events)
        {
            if (event == QUIT)
            {
                done = true;
            }
        }

        display->Render();
    }

    std::cout << "Main Loop finished" << std::endl;
}

/* INITIALIZATION */

void Main::InitModel()
{
    world = new World();

    std::cout << "\x1b[2mInitialized model\x1b[0m" << std::endl;
}

void Main::InitView()
{
    display = new Display();

    std::cout << "\x1b[2mInitialized view\x1b[0m" << std::endl;
}

void Main::InitController()
{
    std::cout << "\x1b[2mInitialized controller\x1b[0m" << std::endl;
}

/* DEINITIALIZATION */

void Main::DeinitModel()
{
    delete world;

    std::cout << "\x1b[2mDeinitialized model\x1b[0m" << std::endl;
}

void Main::DeinitView()
{
    delete display;
    
    std::cout << "\x1b[2mDeinitialized view\x1b[0m" << std::endl;
}

void Main::DeinitController()
{
    std::cout << "\x1b[2mDeinitialized controller\x1b[0m" << std::endl;
}