#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Player
{
private:
    const char *idleDownLocation = "../assets/Player/Idle/idle_down.png";
    const char *idleUpLocation = "../assets/Player/Idle/idle_up.png";
    const char *idleRightLocation = "../assets/Player/Idle/idle_right.png";
    const char *idleLeftLocation = "../assets/Player/Idle/idle_left.png";


   
public:
    SDL_Texture *currentSpriteSheet = nullptr;
    SDL_Texture *idleUpSpriteSheet = nullptr;
    SDL_Texture *idleDownSpriteSheet = nullptr;
    SDL_Texture *idleRightSpriteSheet = nullptr;
    SDL_Texture *idleLeftSpriteSheet = nullptr;


    int idleSpriteSheetWidth;

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

    void playerController(const SDL_Event &e);
    bool Init(SDL_Renderer *r);
    bool Render(SDL_Renderer *r);
    void Update(float dt);
    Player();
    ~Player();
};


