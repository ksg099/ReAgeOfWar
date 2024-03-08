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

	SpriteGo spawnMenu; //�ʻ��� ���� �ͷ� ���׷��̵� �ϴ� ui�κ�
	SpriteGo spawnUnit; //���� �ϴ� ui�κ�
	SpriteGo spawnTurrent; //�ͷ� �ϴ� ui�κ�

	//SpriteGo* moneyExp; //���� ��ȭ�� ����ġ�� �����ִ� ui�κ�

	//sf::RectangleShape //������ ������ �ӵ���, �ִ� ��ȯ ���� ������ �����ִ� �κ�

	//sf::Vector2f PlayerHpSize ü�� ui�� ui�䰡 �ƴ϶� ���� ���ε� ���⿡ ����ϳ�
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

