#include <iostream>

#include "main.hpp"

void Main::Loop()
{
    std::cout << "Main Loop started" << std::endl;

    done = false;
    while (!done)
    {
        Update();
        Render();
    }

    std::cout << "Main Loop finished" << std::endl;
}

void Main::Update()
{
    std::vector<SDL_Event> events = display->GetEvents();
    for (SDL_Event event : events)
    {
        if (event.type == SDL_QUIT)
        {
            done = true;
        }

        if (event.type == SDL_KEYDOWN)
        {
            std::cout << (char)event.key.keysym.sym << std::endl;
        }
    }
}

void Main::Render()
{
    display->Render();
}

/* INITIALIZATION */

Main::Main()
{
    std::cout << std::endl;

    InitModel();
    InitView();
    InitController();

    std::cout << "Initialization completed" << std::endl;
}

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

Main::~Main()
{
    DeinitModel();
    DeinitView();
    DeinitController();

    std::cout << "Deinitialization completed" << std::endl;
    std::cout << std::endl;
}

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