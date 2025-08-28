#include "Spawner.hpp"


void Spawner::SpawnMob(SDL_Renderer *r, float x, float y) {
    Mob mob;
    mob.Init(r, "Zombie", "../assets/Mob/WhiteMan/idle.png", "../assets/Mob/WhiteMan/walk.png", 80, 80, 200, 200);
    mobs.push_back(std::move(mob));
}

void Spawner::Update(SDL_Renderer *r, float dt, float playerX, float playerY)
{
    handleSpawnTimer(dt);
    if(shouldSpawn){
        srand(time(NULL));
        int randomX = rand() % 201;
        int randomY = rand() % 201;
        SpawnMob(r, (float)randomX, (float)randomY);
        shouldSpawn = false;
    }
    for (auto& mob : mobs) {
        mob.Update(dt, playerX, playerY);
    }

}

void Spawner::handleSpawnTimer(float dt)
{
    spawnTimer += dt;
    if (spawnTimer >= spawnInterval) {
        shouldSpawn = true;
        spawnTimer = 0.0f;
    }
}

void Spawner::Render(SDL_Renderer *r)
{
    for (auto& mob : mobs) {
        mob.Render(r);
    }
}

Spawner::Spawner()
{

}

Spawner::~Spawner()
{

}