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

    const char *runDownLocation = "../assets/Player/Run/run_down.png";
    const char *runUpLocation = "../assets/Player/Run/run_up.png";
    const char *runRightLocation = "../assets/Player/Run/run_right.png";
    const char *runLeftLocation = "../assets/Player/Run/run_left.png";

   
public:
    SDL_Texture *currentSpriteSheet = nullptr;

    //Idle SpriteSheets
    SDL_Texture *idleUpSpriteSheet = nullptr;
    SDL_Texture *idleDownSpriteSheet = nullptr;
    SDL_Texture *idleRightSpriteSheet = nullptr;
    SDL_Texture *idleLeftSpriteSheet = nullptr;

    //Run SpriteSheets
    SDL_Texture *runUpSpriteSheet = nullptr;
    SDL_Texture *runDownSpriteSheet = nullptr;
    SDL_Texture *runRightSpriteSheet = nullptr;
    SDL_Texture *runLeftSpriteSheet = nullptr;


    int idleSpriteSheetWidth;

    SDL_FRect idleRect ={
        0.0f,
        0.0f,
        96.0f,
        80.0f,
    };

    SDL_FRect runRect ={
        0.0f,
        0.0f,
        96.0f,
        80.0f,
    };

    SDL_FRect currentFrameRect = idleRect;
    SDL_FRect playerRect ={100.0f, 100.0f, 100.0f, 100.0f};
    int canvasHeight = 80;
    int canvasWidth = 96;
    int playerHeight = 34; 
    int playerWidth = 22;

    float velocityX = 0.0f;
    float velocityY = 0.0f;
    float movementSpeed = 200.0f;



    void playerController(const SDL_Event &e);
    void movementController();
    SDL_FRect getCollisionRect();
    bool Init(SDL_Renderer *r);
    bool Render(SDL_Renderer *r);
    void Update(float dt);
    Player();
    ~Player();
};


