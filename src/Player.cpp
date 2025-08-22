#include "Player.hpp"

Player::Player()
{

}
Player::~Player()
{
}

bool Player::Init(SDL_Renderer *r)
{

    //Load all Idle SpriteSheets
    idleDownSpriteSheet = IMG_LoadTexture(r, idleDownLocation);

    if(idleDownSpriteSheet == nullptr)
    {
        SDL_Log("IdleDownSpritesheet failed to load");
        return false;
    }

    SDL_SetTextureScaleMode(idleDownSpriteSheet, SDL_SCALEMODE_NEAREST);

    idleUpSpriteSheet = IMG_LoadTexture(r, idleUpLocation);
    
    if(idleUpSpriteSheet == nullptr)
    {
        SDL_Log("IdleUpSpritesheet failed to load");
        return false;
    }

    SDL_SetTextureScaleMode(idleUpSpriteSheet, SDL_SCALEMODE_NEAREST);

    idleLeftSpriteSheet = IMG_LoadTexture(r, idleLeftLocation);
    
    if(idleLeftSpriteSheet == nullptr)
    {
        SDL_Log("IdleLeftSpritesheet failed to load");
        return false;
    }

    SDL_SetTextureScaleMode(idleLeftSpriteSheet, SDL_SCALEMODE_NEAREST);
    
    idleRightSpriteSheet = IMG_LoadTexture(r, idleRightLocation);
    
    if(idleRightSpriteSheet == nullptr)
    {
        SDL_Log("IdleRightSpritesheet failed to load");
        return false;
    }

    SDL_SetTextureScaleMode(idleRightSpriteSheet, SDL_SCALEMODE_NEAREST);
    
    currentSpriteSheet = idleDownSpriteSheet;



    //Load all Run SpriteSheets
    runDownSpriteSheet = IMG_LoadTexture(r, runDownLocation);

    if(runDownSpriteSheet == nullptr)
    {
        SDL_Log("runDownSpritesheet failed to load");
        return false;
    }

    SDL_SetTextureScaleMode(runDownSpriteSheet, SDL_SCALEMODE_NEAREST);

    runUpSpriteSheet = IMG_LoadTexture(r, runUpLocation);
    
    if(runUpSpriteSheet == nullptr)
    {
        SDL_Log("runUpSpritesheet failed to load");
        return false;
    }

    SDL_SetTextureScaleMode(runUpSpriteSheet, SDL_SCALEMODE_NEAREST);

    runLeftSpriteSheet = IMG_LoadTexture(r, runLeftLocation);
    
    if(runLeftSpriteSheet == nullptr)
    {
        SDL_Log("runLeftSpritesheet failed to load");
        return false;
    }

    SDL_SetTextureScaleMode(runLeftSpriteSheet, SDL_SCALEMODE_NEAREST);
    
    runRightSpriteSheet = IMG_LoadTexture(r, runRightLocation);
    
    if(runRightSpriteSheet == nullptr)
    {
        SDL_Log("runRightSpritesheet failed to load");
        return false;
    }

    SDL_SetTextureScaleMode(runRightSpriteSheet, SDL_SCALEMODE_NEAREST);
    
    currentSpriteSheet = idleDownSpriteSheet;



    return true;
}

void Player::playerController(const SDL_Event &e)
{
    if (e.type == SDL_EVENT_KEY_DOWN) {
        if (e.key.scancode == SDL_SCANCODE_A) 
        {
            currentSpriteSheet = runLeftSpriteSheet;
        }
        else if(e.key.scancode == SDL_SCANCODE_D)
        {
            currentSpriteSheet = runRightSpriteSheet;
        }
        else if(e.key.scancode == SDL_SCANCODE_W)
        {
            currentSpriteSheet = runUpSpriteSheet;
        }
        else if(e.key.scancode == SDL_SCANCODE_S)
        {
            currentSpriteSheet = runDownSpriteSheet;
        }
    }
    else if(e.type == SDL_EVENT_KEY_UP)
    {
        if (e.key.scancode == SDL_SCANCODE_A) 
        {
            currentSpriteSheet = idleLeftSpriteSheet;
        }
        else if(e.key.scancode == SDL_SCANCODE_D)
        {
            currentSpriteSheet = idleRightSpriteSheet;
        }
        else if(e.key.scancode == SDL_SCANCODE_W)
        {
            currentSpriteSheet = idleUpSpriteSheet;
        }
        else if(e.key.scancode == SDL_SCANCODE_S)
        {
            currentSpriteSheet = idleDownSpriteSheet;
        }
    }
}

void Player::Update(float dt)
{
}

bool Player::Render(SDL_Renderer *r)
{
    const Uint32 frameDuration = 100;

    int currentSpriteSheetWidth = currentSpriteSheet->w;

    int animationFrames = currentSpriteSheetWidth / canvasWidth;

    Uint32 ticks = SDL_GetTicks();
    int currentFrame = (ticks / frameDuration) % static_cast<int>(animationFrames);
    SDL_Log("%d", currentFrame);
    currentFrameRect.x = 0 + canvasWidth * currentFrame;    
    SDL_Log("%f", currentFrameRect.x);


    if(!SDL_RenderTexture(r, currentSpriteSheet, &currentFrameRect, &playerRect))
    {
        return false;
    }

    return true;

}
