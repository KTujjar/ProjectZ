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

    SDL_FRect currentFrameRect;
    SDL_Texture *currentSpriteSheet = nullptr;

    //Takes Renderer | Mob Name | IdleSpriteSheet path | WalkSpriteSheet path | canvasWidth(per frame) | canvasHeight(per frame)
    void Init(SDL_Renderer *r, const char* name, const char* idleLoc, const char* walkLoc, float cW, float cH);
    bool Render(SDL_Renderer *r);
    Mob();
    ~Mob();
};

