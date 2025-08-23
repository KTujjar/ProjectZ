#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "Global.hpp"
#include "Player.hpp"
#include "Mob.hpp"


class Game
{
private:
    void update(double delta);
    void renderWindow();
    void render();
    void updateFPS(double dt);
    void processEvents();
    void loadTextures();
    void handleWindowEvent(const SDL_Event &e);
    void handleMouseEvent(const SDL_Event &e);


    
    //Iniatlize other classes
    Player player;
    Mob whiteMan;



    //Initialize window variables
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface* screenSurface = NULL;
    SDL_Event e;   
    const SDL_PixelFormatDetails* details = NULL;

    Uint32 flags;

    SDL_DisplayMode *windowed;
    SDL_DisplayMode *fullscreen;

public:
    Game();
    ~Game();
    void run();
};