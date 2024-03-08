#include "pch.h"
#include "UiHud.h"

UiHud::UiHud(const std::string& name) : SpriteGo(name)
{
}

void UiHud::Init()
{
	textExp.Init();
	textMoney.Init();

	spawnMenu.SetTexture("graphics/AgeGameUi.png");
	spawnUnit.SetTexture("graphics/Age1UnitUi.png");
	spawnTurrent.SetTexture("graphics/Age1UiTurret.png");


	sf::Font& font = RES_MGR_FONT.Get("fonts/LiberationSans.ttf");
	textExp.Set(font, "aaaaaaaaaa", textSize, sf::Color::White);
	textMoney.Set(font, "bbbbbbbbb", textSize, sf::Color::White);

	textMoney.SetOrigin(Origins::TL);
	textExp.SetOrigin(Origins::TL);
	spawnMenu.SetOrigin(Origins::TR);
	spawnUnit.SetOrigin(Origins::TR);
	spawnTurrent.SetOrigin(Origins::TR);

	textExp.SetPosition({ 500.f, 500.f });
	textMoney.SetPosition({ 500.f, 600.f });
	spawnMenu.SetPosition({ 900.f, -100.f });
	spawnUnit.SetPosition(spawnMenu.GetPosition());
	spawnTurrent.SetPosition(spawnMenu.GetPosition());
	spawnTurrent.SetActive(false);
	spawnUnit.SetActive(false);

	//if (spawnMenu.GetActive())
	//{
	//	spawnUnit.SetActive(false);
	//	spawnTurrent.SetActive(false);
	//}
}

void UiHud::Reset()
{
	textExp.Reset();
	textMoney.Reset();
	spawnMenu.Reset();
	spawnUnit.Reset();
	spawnTurrent.Reset();
}

void UiHud::Update(float dt)
{
	//if (유닛 ui버튼 클릭시)
	//{
	//	spawnUnit.SetActive(true);
	//	spawnMenu.SetActive(false);
	//}
	//if (유닛 터렛버튼 클릭시)
	//{
	//	spawnTurrent.SetActive(true);
	//	spawnMenu.SetActive(false);
	//}
}

void UiHud::SetExp(int s)
{
	textExp.SetString(formatExp + std::to_string(s));
}

void UiHud::SetMoney(int s)
{
	textMoney.SetString(formatMoney + std::to_string(s));
}

void UiHud::Draw(sf::RenderWindow& window)
{
	spawnMenu.Draw(window);
	spawnUnit.Draw(window);
	spawnTurrent.Draw(window);
	textExp.Draw(window);
	textMoney.Draw(window);

}