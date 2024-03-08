#include "pch.h"
#include "PlayerBuilding.h"

PlayerBuilding::PlayerBuilding(const std::string& name) : SpriteGo(name)
{
}

void PlayerBuilding::Init()
{


	SpriteGo::Init();

}

void PlayerBuilding::Release()
{
	SpriteGo::Release();
}

void PlayerBuilding::Reset()
{
	SpriteGo::Reset();
}

void PlayerBuilding::Update(float dt)
{
	SpriteGo::Update(dt);
}

void PlayerBuilding::OnDamage(int damage)
{
	
}

void PlayerBuilding::OnDefeat()
{
	
}

void PlayerBuilding::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);
}