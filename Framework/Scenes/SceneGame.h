#pragma once
#include "Scene.h"
#include "pch.h"

class SpriteGo;

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
	

	/*UiHud* hud;*/

	SpriteGo* background;
	SpriteGo* Playerbuilding;
	SpriteGo* enemybuilding;
	SpriteGo* age1Turrent1;


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

};

