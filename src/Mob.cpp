#include "Mob.hpp"


Mob::Mob()
{

}
Mob::~Mob()
{
    
}

void Mob::Init(SDL_Renderer *r, const char* name, const char* idleLoc, const char* walkLoc, float cW, float cH)
{
    mobName = name;
    idleSpriteSheetLocation = idleLoc;
    walkSpriteSheetLocation = walkLoc;
    canvasWidth = cW;
    canvasHeight = cH;



    idleSpriteSheet = IMG_LoadTexture(r, idleSpriteSheetLocation);

    if(idleSpriteSheet == nullptr)
    {
        SDL_Log("Could Not load %s Idle Texture", mobName);

    }

    SDL_SetTextureScaleMode(idleSpriteSheet, SDL_SCALEMODE_NEAREST);

    walkSpriteSheet = IMG_LoadTexture(r, walkSpriteSheetLocation);

    if(walkSpriteSheet == nullptr)
    {
        SDL_Log("Could Not load %s Idle Texture", mobName);

    }

    SDL_SetTextureScaleMode(walkSpriteSheet, SDL_SCALEMODE_NEAREST);

    idleDownRect = {0, canvasHeight, canvasWidth, canvasHeight};
    mobRect = {200,200,125,125};

    currentFrameRect = idleDownRect;
    currentSpriteSheet = idleSpriteSheet;
}

bool Mob::Render(SDL_Renderer *r)
{
    const Uint32 frameDuration = 100;

    int currentSpriteSheetWidth = currentSpriteSheet->w;

    int animationFrames = currentSpriteSheetWidth / canvasWidth;

    Uint32 ticks = SDL_GetTicks();
    int currentFrame = (ticks / frameDuration) % static_cast<int>(animationFrames);
    //SDL_Log("%d", currentFrame);
    currentFrameRect.x = 0 + canvasWidth * currentFrame;    
    //SDL_Log("%f", currentFrameRect.x);


    if(!SDL_RenderTexture(r, currentSpriteSheet, &currentFrameRect, &mobRect))
    {
        return false;
    }

    return true;

}