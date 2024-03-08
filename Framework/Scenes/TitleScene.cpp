#include "pch.h"
#include "TitleScene.h"
#include "SpriteGo.h"
#include "TextGo.h"


TitleScene::TitleScene(SceneIds id) : Scene(id)
{
}


void TitleScene::Enter()
{
	Scene::Enter();

	//sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();

	//배경 이미지 사이즈임
	sf::Vector2f viewSize = sf::Vector2f(1577, 504);
	sf::Vector2f centerPos = viewSize * 0.f;

	uiView.setSize(viewSize);
	uiView.setCenter(centerPos);

	FRAMEWORK.GetWindow().setView(uiView);

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
	//titleText->SetPosition(centerPos->GetPosition());
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
	optionclose->SetPosition({ titleoption->GetPosition().x, titleoption->GetPosition().y + 50.f });
	optionclose->SetOrigin(Origins::MC);
	optionclose->SetActive(false);
	//AddGo(optionclose, Ui); draw쪽에서 해줘서 옵션버튼이 팝업창에 가려지지 않게 해줌
	//혹은 팝업창을 클래스로 만들어서 위치를 바꿔주면 가능하다.

	Scene::Init();
}

void TitleScene::Release()
{
	Scene::Release();
}


void TitleScene::Update(float dt)
{
	Scene::Update(dt);

	FRAMEWORK.GetWindow().setView(worldView);
	//마우스 좌표를 게임내 월드의 좌표로 변환
	sf::Vector2f currMousePos = InputMgr::GetMousePos();
	sf::Vector2f worldMousePos = ScreenToUi((sf::Vector2i)currMousePos);




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
			optionsShape.setPosition(titleoption->GetPosition());
			optionsShape.setSize({500.f, 250.f});
			optionsShape.setFillColor(sf::Color::Blue);
			Utils::SetOrigin(optionsShape, Origins::MC);
			optionclose->SetActive(false);

		}

		//옵션 닫기 버튼이 없다면
		if (!optionclose->GetActive())
		{
			optionclose->SetActive(true);
			titleoption->SetActive(false);
			titlestart->SetActive(false);
		}

		//팝업창의 영역을 가져와서 마우스 클릭시
		sf::FloatRect optioncloseBounds = optionclose->GetGlobalBounds();
		if (optioncloseBounds.contains(worldMousePos))
		{
			optionclose->SetActive(false);
			titleoption->SetActive(true);
			titlestart->SetActive(true);
		}

	}

}

void TitleScene::Draw(sf::RenderWindow& window)
{
	
	Scene::Draw(window);

	//옵션 창이 켜졌을 경우 윈도우와 닫기 버튼을 그려줌
	//draw에서 팝업창을 그려주기 있기떄문에 조건에서 팝업닫기만 눌러도 창이 꺼진다.
	if(optionclose->GetActive())
	{
		window.draw(optionsShape);
		optionclose->Draw(window);
	}
	
	//shape->Draw(window);
	//Draw(titleTexture);
	

}
