#ifndef main_hpp
#define main_hpp

#include "world.hpp"
#include "display.hpp"
#include "rect.hpp"
#include "player.hpp"

class Main
{
    public:
        Main();
        ~Main();
        void loop();
    private:
        void render();
        void update();
        void initModel();
        void initView();
        void initController();
        void deinitModel();
        void deinitView();
        void deinitController();
        void handleKeystate();
        void handleEvents();
        void handleKeystroke(SDL_Event *event);
        bool done;
        World *world;
        Rect *camera;
        Display *display;
        Player *player;
        int cameraSpeed;
};

#endif