#ifndef main_hpp
#define main_hpp

#include "world.hpp"
#include "display.hpp"

class Main
{
    public:
        Main();
        ~Main();
        void Loop();
    private:
        void Render();
        void Update();
        void InitModel();
        void InitView();
        void InitController();
        void DeinitModel();
        void DeinitView();
        void DeinitController();
        World *world;
        Display *display;
        bool done;
};

#endif