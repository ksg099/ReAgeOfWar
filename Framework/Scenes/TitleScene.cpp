#include "pch.h"
#include "TitleScene.h"
#include "SpriteGo.h"
#include "TextGo.h"


TitleScene::TitleScene(SceneIds id) : Scene(id)
{
}

void TitleScene::Init()
{

	//타이틀 씬 배경 출력
	titleTexture = new SpriteGo("TitleBackGround");
	titleTexture->SetTexture("graphics/BackGround.png");
	titleTexture->SetPosition({0.f, 0.f});
	titleTexture->SetOrigin(Origins::MC);
	//titleText->sortLayer = 1;
	AddGo(titleTexture, Ui);

	//타이틀 씬 제목 출력
	titleText = new TextGo("Title");
	titleText->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Age Of War", 100, sf::Color::White);
	titleText->SetPosition({ 0.f, -180.f });
	titleText->SetOrigin(Origins::MC);
	//titleText->sortLayer = 1;
	AddGo(titleText, Ui);

	//타이틀 씬 게임시작 버튼 출력
	titlestart = new TextGo("titlestart");
	titlestart->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Start", 80, sf::Color::White);
	titlestart->SetPosition({ 0.f, -50.f });
	titlestart->SetOrigin(Origins::MC);
	//titleText->sortLayer = 1;
	AddGo(titlestart, Ui);

	//타이틀 씬 옵션 버튼 출력
	titleoption = new TextGo("titleoption");
	titleoption->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Options", 80, sf::Color::White);
	titleoption->SetPosition({ 0.f, 70.f });
	titleoption->SetOrigin(Origins::MC);
	//titleText->sortLayer = 1;
	AddGo(titleoption, Ui);

	//타이틀 씬 옵션 창 출력
	//optionsWindow = new SpriteGo("TitleBackGround");
	//optionsWindow->SetTexture("graphics/BackGround.png");
	//optionsWindow->SetPosition({ 0.f, 0.f });
	//optionsWindow->SetOrigin(Origins::MC);
	//AddGo(optionsWindow);

	//옵션 버튼내 닫기 버튼
	optionclose = new TextGo("optionclose");
	optionclose->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Close", 80, sf::Color::White);
	optionclose->SetPosition({ 0.f, 0.f });
	optionclose->SetOrigin(Origins::MC);
	optionclose->SetActive(false);
	//titleText->sortLayer = 1;
	AddGo(optionclose, Ui);

	Scene::Init();
}

void TitleScene::Release()
{
	Scene::Release();
}

void TitleScene::Enter()
{
	Scene::Enter();

	sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();

	//배경 이미지 사이즈임
	sf::Vector2f viewSize = sf::Vector2f(1577, 504);
	sf::Vector2f centerPos = viewSize * 0.f;

	uiView.setSize(viewSize);
	uiView.setCenter(centerPos);

	FRAMEWORK.GetWindow().setView(uiView);

}

void TitleScene::Update(float dt)
{
	Scene::Update(dt);


	FRAMEWORK.GetWindow().setView(worldView);
	//마우스 좌표를 게임내 월드의 좌표로 변환
	sf::Vector2i mousePos = sf::Mouse::getPosition(FRAMEWORK.GetWindow());
	sf::Vector2f worldMousePos = FRAMEWORK.GetWindow().mapPixelToCoords(mousePos);

	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	{
		if (titleText->GetGlobalBounds().contains(worldMousePos))
		{
			SCENE_MGR.ChangeScene(SceneIds::SceneGame);
		}
	}


	//mousecursor->SetPosition(ScreenToUi((sf::Vector2i)InputMgr::GetMousePos()));

	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	{
		//게임시작 버튼 클릭시
		//경계 범위를 가져와서 마우스가 있을때 검사하기
		sf::FloatRect titlestartBounds = titlestart->GetGlobalBounds();
		if (titlestartBounds.contains(worldMousePos))
		{
			SCENE_MGR.ChangeScene(SceneIds::SceneGame);
		}

		//옵션버튼 클릭시
		//경계 범위를 가져와서 마우스가 있을때 검사하기
		sf::FloatRect titleoptionBounds = titleoption->GetGlobalBounds();
		if (titleoptionBounds.contains(worldMousePos))
		{
			if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
			{
				//사각형 출력하게
			}
		}

	}

}

void TitleScene::Draw(sf::RenderWindow& window)
{
	//window.setView(worldView);
	Scene::Draw(window);
	
	//Draw(titleTexture);
	

}
