#pragma once
#include "GameObject.h"
#include "SpriteGo.h"
#include "TextGo.h"
class UiHud : public SpriteGo
{
protected:

	std::string formatExp = "Exp : ";
	std::string formatMoney = "Money : ";

	TextGo textExp;
	TextGo textMoney;

	SpriteGo spawnMenu; //필살기랑 유닛 터렛 업그레이드 하는 ui부분
	SpriteGo spawnUnit; //유닛 하는 ui부분
	SpriteGo spawnTurrent; //터렛 하는 ui부분

	//SpriteGo* moneyExp; //현재 재화와 경험치를 보여주는 ui부분

	//sf::RectangleShape //유닛이 나오는 속도랑, 최대 소환 가능 유닛을 보여주는 부분

	//sf::Vector2f PlayerHpSize 체력 ui는 ui뷰가 아니라 월드 뷰인데 여기에 써야하나
	//sf::Vector2f EnemyHpSize 
	float textSize = 50.f;
	int ExpCount = 0.f;
	int MoneyCount = 0.f;

public:


	UiHud(const std::string& name = "");
	~UiHud() override = default;
	void Update(float dt);

	void Init() override;
	void Reset() override;
	void Draw(sf::RenderWindow& window) override;

	void SetExp(int s);
	void SetMoney(int s);


};

