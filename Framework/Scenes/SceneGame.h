#pragma once
#include "Scene.h"
#include <fstream>
#include <iostream>
#include "pch.h"
#include "TextGo.h"


class SpriteGo;
class UiHud;
class PlayerBuilding;
class EnemyBuilding;
class Turret;


class SceneGame : public Scene
{
public:
	enum class Status
	{
		Title,
		Playing,
		NextWave,
		GameOver,
		Pause,
	};

protected:
	Status currentStatus;
	

	UiHud* hud;

	SpriteGo* background;
	SpriteGo* Playerbuilding;
	SpriteGo* enemybuilding;
	SpriteGo* age1Turrent1;

	TextGo* pauseclose;

	sf::RectangleShape pauseshape;

	bool ispause = false;

	int Exp = 0.f;
	int Money = 175.f;

	float viewMoveSpeed = 350.f;
	float worldLeft = 0.f;
	float worldRight = 0.f; 
	float worldWidth = worldView.getSize().x; //월드 너비

	//sf::Vector2f prevMousPos;


public:
	SceneGame(SceneIds id);
	~SceneGame() override = default;

	Status GetStatus() const { return currentStatus; }
	void SetStatus(Status newStatus);

	//UiHud* GetHud() const
	//{
	//	return hud;
	//}

	void Init() override;
	void Release() override;

	void Enter() override;
	void Exit() override;
	void Reset();

	void Update(float dt) override;
	void FixedUpdate(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void AddExp(int s);
	void AddMoney(int s);

};

