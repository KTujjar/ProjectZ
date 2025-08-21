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

    return true;
}

void Player::playerController(const SDL_Event &e)
{
    if (e.type == SDL_EVENT_KEY_DOWN) {
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
    int currentSpriteSheetWidth = currentSpriteSheet->w;

    int animationFrames = currentSpriteSheetWidth / canvasWidth;
}

bool Player::Render(SDL_Renderer *r)
{
    if(!SDL_RenderTexture(r, currentSpriteSheet, &idleRect, &playerRect))
    {
        return false;
    }

    return true;

}
