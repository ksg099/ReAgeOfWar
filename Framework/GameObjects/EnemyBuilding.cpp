#include "pch.h"
#include "EnemyBuilding.h"

EnemyBuilding::EnemyBuilding(const std::string& name) : SpriteGo(name)
{
}

void EnemyBuilding::Init()
{
	SpriteGo::Init();
}

void EnemyBuilding::Release()
{
	SpriteGo::Release();

}

void EnemyBuilding::Reset()
{
	SpriteGo::Reset();
}

void EnemyBuilding::Update(float dt)
{
	SpriteGo::Update(dt);
}

void EnemyBuilding::OnDamage(int damage)
{
}

void EnemyBuilding::OnDefeat()
{
}

void EnemyBuilding::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);
}