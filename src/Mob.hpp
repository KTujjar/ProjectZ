#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Mob
{
private:
    const char *mobName = nullptr;

    const char *idleSpriteSheetLocation = nullptr;
    const char *walkSpriteSheetLocation = nullptr;

    float canvasWidth;
    float canvasHeight;

    SDL_Texture *idleSpriteSheet = nullptr;
    SDL_Texture *walkSpriteSheet = nullptr;

    SDL_FRect idleDownRect;
    SDL_FRect mobRect;
public:
    float movementSpeed = 100.0f;   

    SDL_FRect currentFrameRect;
    SDL_Texture *currentSpriteSheet = nullptr;

    //Takes Renderer | Mob Name | IdleSpriteSheet path | WalkSpriteSheet path | canvasWidth(per frame) | canvasHeight(per frame)
    void Init(SDL_Renderer *r, const char* name, const char* idleLoc, const char* walkLoc, float cW, float cH, float X, float Y);
    bool Render(SDL_Renderer *r);
    SDL_FRect getCollisionRect();
    void Update(float dt, float playerX, float playerY);
    Mob();
    ~Mob();
};

