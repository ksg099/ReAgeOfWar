#pragma once
#include "SpriteGo.h"
class PlayerBuilding : public SpriteGo
{
protected:
	int maxHp = 500;
	int hp = 500;

	SpriteGo playerbuilding;
public:
	PlayerBuilding(const std::string& name = "");
	~PlayerBuilding() override = default;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void OnDamage(int damage);
	void OnDefeat();

	int GetHp() { return hp; }
};

