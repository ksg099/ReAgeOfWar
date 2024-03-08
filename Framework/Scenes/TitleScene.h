#pragma once
#include "Scene.h"

class SpriteGo;
class TextGo;

class TitleScene : public Scene
{

protected:
	SpriteGo* titleTexture;
	SpriteGo* optionsWindow;

	TextGo* titlestart;
	TextGo* titleoption;
	TextGo* optionclose;
	TextGo* titleText;
	
	sf::Vector2f viewSize;
	sf::Vector2f textureCenter;

	sf::RectangleShape optionsShape;

public:
	TitleScene(SceneIds id);
	~TitleScene()override = default;

	void Init() override;
	void Release() override;

	void Enter() override;

	void Update(float dt) override;

	void Draw(sf::RenderWindow& window) override;
};

