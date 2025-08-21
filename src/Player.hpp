#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Player
{
private:
    const char *idleDownLocation = "../assets/Player/Idle/idle_down.png";
   
public:
    SDL_Texture *idleDownSpriteSheet = nullptr;
    SDL_FRect idleRect ={
        0.0f,
        0.0f,
        80.0f,
        96.0f,
    };

    SDL_FRect playerRect ={100.0f, 100.0f, 100.0f, 100.0f};



    int canvasHeight = 96;
    int canvasWidth = 80;
    int playerHeight = 34; 
    int playerWidth = 22;


    bool Init(SDL_Renderer *r);
    bool Render(SDL_Renderer *r);
    Player();
    ~Player();
};


