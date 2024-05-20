#include <iostream>

#include "main.hpp"

const int WIDTH = 1024, HEIGHT = 1024;

const float playerSpeedModifier = 10;

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
        Vectorf(0.0, 0.0)
    );
    player->stats.speed.set(1);
    player->position.x = worldWidth / 2;
    player->position.y = worldWidth / 2;
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
    if (keyState[SDL_SCANCODE_W]) player->position.y -= player->stats.speed.level / playerSpeedModifier;
    if (keyState[SDL_SCANCODE_S]) player->position.y += player->stats.speed.level / playerSpeedModifier;
    if (keyState[SDL_SCANCODE_A]) player->position.x -= player->stats.speed.level / playerSpeedModifier;
    if (keyState[SDL_SCANCODE_D]) player->position.x += player->stats.speed.level / playerSpeedModifier;

    // Debug
    if (keyState[SDL_SCANCODE_P])
        std::cout << "\x1b[2mplayer pos: " << player->position.x << ' ' << player->position.y << std::endl;
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