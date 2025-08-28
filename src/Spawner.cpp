#include "Spawner.hpp"

void Spawner::SpawnMob(SDL_Renderer *r, float x, float y) {
    Mob mob;
    mob.Init(r, "Zombie", "../assets/Mob/WhiteMan/idle.png", "../assets/Mob/WhiteMan/walk.png", 80, 80, x, y);
    mobs.push_back(std::move(mob));
}

void Spawner::Update(SDL_Renderer *r, float dt, float playerX, float playerY)
{
    handleSpawnTimer(dt);
    if(shouldSpawn){
        srand(time(NULL));
        // int randomX = rand() % (static_cast<int>(playerX) + 150);
        // int randomY = rand() % (static_cast<int>(playerY) + 150);

        float angle = (rand() / (float)RAND_MAX) * 2.0f * M_PI;  // random direction
        float distance = 300.0f;

        float spawnX = playerX + cosf(angle) * distance;
        float spawnY = playerY + sinf(angle) * distance;

        SDL_Log("SpawnX: %f \n SpawnY: %f\n", spawnX, spawnY);

        SpawnMob(r, spawnX, spawnY);
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