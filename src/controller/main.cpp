#include <iostream>

#include "main.hpp"

const int WIDTH = 1024, HEIGHT = 1024;

/*
    INITIALIZATION 
*/

Main::Main()
{
    std::cout << std::endl;

    initModel();
    initView();
    initController();

    std::cout << "Initialization completed" << std::endl;
}

void Main::initModel()
{
    std::cout << "\x1b[2mInitializing model...\x1b[0m" << std::endl;

    world = new World();
    camera = new Rect(0, 0, WIDTH, HEIGHT);
    cameraSpeed = 5;

    player = new Player(
        LingualString("adm!n"),
        StatSet(),
        Rect(0, 0, 16, 16)
    );
    player->stats.speed.set(5);
}

void Main::initView()
{
    std::cout << "\x1b[2mInitializing view...\x1b[0m" << std::endl;

    const Rect windowDimensions(0, 0, WIDTH, HEIGHT);
    display = new Display(windowDimensions, camera, world, player);
}

void Main::initController()
{
    std::cout << "\x1b[2mInitializing controller...\x1b[0m" << std::endl;
}

/* 
    MAINLOOP 
*/

void Main::loop()
{
    std::cout << "Main Loop started" << std::endl;

    done = false;
    while (!done)
    {
        update();
        render();
    }

    std::cout << "Main Loop finished" << std::endl;
}

void Main::update()
{
    handleKeystate();
    handleEvents();
}

void Main::render()
{
    display->render();
}

/* UPDATE */

void Main::handleKeystate()
{
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);
    
    // Camera movement
    if (keyState[SDL_SCANCODE_UP]) camera->top -= cameraSpeed;
    if (keyState[SDL_SCANCODE_DOWN]) camera->top += cameraSpeed;
    if (keyState[SDL_SCANCODE_LEFT]) camera->left -= cameraSpeed;
    if (keyState[SDL_SCANCODE_RIGHT]) camera->left += cameraSpeed;

    // Player movement
    if (keyState[SDL_SCANCODE_W]) player->rect.top -= player->stats.speed.level;
    if (keyState[SDL_SCANCODE_S]) player->rect.top += player->stats.speed.level;
    if (keyState[SDL_SCANCODE_A]) player->rect.left -= player->stats.speed.level;
    if (keyState[SDL_SCANCODE_D]) player->rect.left += player->stats.speed.level;
}

void Main::handleEvents()
{
    std::vector<SDL_Event> events = display->getEvents();
    for (SDL_Event event : events)
    {
        if (event.type == SDL_QUIT)
        {
            done = true;
        }

        if (event.type == SDL_KEYDOWN)
        {
            handleKeystroke(&event);
        }
    }
}

void Main::handleKeystroke(SDL_Event *event)
{
    if (event->type != SDL_KEYDOWN)
    {
        return;
    }

    switch (event->key.keysym.sym)
    {
        case SDLK_ESCAPE:
            done = true;
            break;
        case SDLK_r:
            world->reinitializeBlocks();
            break;
        default:
            break;
    }
}

/* 
    DEINITIALIZATION 
*/

Main::~Main()
{
    deinitModel();
    deinitView();
    deinitController();

    std::cout << "Deinitialization completed" << std::endl;
    std::cout << std::endl;
}

void Main::deinitModel()
{
    std::cout << "\x1b[2mDeinitializing model...\x1b[0m" << std::endl;

    delete world;
    world = NULL;

    delete camera;
    camera = NULL;
}

void Main::deinitView()
{
    std::cout << "\x1b[2mDeinitializing view...\x1b[0m" << std::endl;

    delete display;
}

void Main::deinitController()
{
    std::cout << "\x1b[2mDeinitializing controller...\x1b[0m" << std::endl;
}