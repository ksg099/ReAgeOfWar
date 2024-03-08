#pragma once
#include "SpriteGo.h"
class EnemyBuilding : public SpriteGo
{
protected:
	int maxHp = 500;
	int hp = 500;

	//SpriteGo EnemyBuilding;
public:
	EnemyBuilding(const std::string& name = "");
	~EnemyBuilding() override = default;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void OnDamage(int damage);
	void OnDefeat();

	int GetHp() { return hp; }
};