#include "Player.hpp"

Player::Player()
{

}
Player::~Player()
{

}

bool Player::Init(SDL_Renderer *r)
{
    idleDownSpriteSheet = IMG_LoadTexture(r, idleDownLocation);

    if(idleDownSpriteSheet == nullptr)
    {
        SDL_Log("IdleDownSpritesheet failed to load");
        return false;
    }

    SDL_SetTextureScaleMode(idleDownSpriteSheet, SDL_SCALEMODE_NEAREST);
    
    return true;
}

bool Player::Render(SDL_Renderer *r)
{
    if(!SDL_RenderTexture(r, idleDownSpriteSheet, &idleRect, &playerRect))
    {
        return false;
    }

    return true;

}
