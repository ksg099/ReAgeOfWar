#include "pch.h"
#include "UiHud.h"

UiHud::UiHud(const std::string& name) : SpriteGo(name)
{
}

void UiHud::Update(float dt)
{

}

void UiHud::Init()
{

}

void UiHud::Reset()
{

}

void UiHud::Draw(sf::RenderWindow& window)
{
	spawnMenu->Draw(window);
	spawnUnit->Draw(window);
	spawnTurrent->Draw(window);
}

void UiHud::SetExp(int s)
{
	textExp.SetString(formatExp + std::to_string(s));
}

void UiHud::SetMoney(int s)
{
	textMoney.SetString(formatMoney + std::to_string(s));
}
