#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <vector>
#include <memory>
#include "Mob.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>





class Spawner
{
private:
    /* data */
public:
    //std::vector<std::unique_ptr<Mob>> mobs;
    std::vector<Mob> mobs;

    float spawnTimer = 0.0f;
    float spawnInterval = 2.0f;
    bool shouldSpawn = false;

    void SpawnMob(SDL_Renderer *r, float x, float y);

    void Update(SDL_Renderer *r, float dt, float playerX, float playerY);
    void handleSpawnTimer(float dt);
    void Render(SDL_Renderer *r);
    Spawner(/* args */);
    ~Spawner();


};
