#include "pch.h"
#include "TitleScene.h"
#include "SpriteGo.h"
#include "TextGo.h"


TitleScene::TitleScene(SceneIds id) : Scene(id)
{
}

void TitleScene::Init()
{

	//Ÿ��Ʋ �� ��� ���
	titleTexture = new SpriteGo("TitleBackGround");
	titleTexture->SetTexture("graphics/BackGround.png");
	titleTexture->SetPosition({0.f, 0.f});
	titleTexture->SetOrigin(Origins::MC);
	//titleText->sortLayer = 1;
	AddGo(titleTexture, Ui);

	//Ÿ��Ʋ �� ���� ���
	titleText = new TextGo("Title");
	titleText->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Age Of War", 100, sf::Color::White);
	titleText->SetPosition({ 0.f, -180.f });
	titleText->SetOrigin(Origins::MC);
	//titleText->sortLayer = 1;
	AddGo(titleText, Ui);

	//Ÿ��Ʋ �� ���ӽ��� ��ư ���
	titlestart = new TextGo("titlestart");
	titlestart->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Start", 80, sf::Color::White);
	titlestart->SetPosition({ 0.f, -50.f });
	titlestart->SetOrigin(Origins::MC);
	//titleText->sortLayer = 1;
	AddGo(titlestart, Ui);

	//Ÿ��Ʋ �� �ɼ� ��ư ���
	titleoption = new TextGo("titleoption");
	titleoption->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Options", 80, sf::Color::White);
	titleoption->SetPosition({ 0.f, 70.f });
	titleoption->SetOrigin(Origins::MC);
	//titleText->sortLayer = 1;
	AddGo(titleoption, Ui);

	//Ÿ��Ʋ �� �ɼ� â ���
	//optionsWindow = new SpriteGo("TitleBackGround");
	//optionsWindow->SetTexture("graphics/BackGround.png");
	//optionsWindow->SetPosition({ 0.f, 0.f });
	//optionsWindow->SetOrigin(Origins::MC);
	//AddGo(optionsWindow);

	//�ɼ� ��ư�� �ݱ� ��ư
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

	//��� �̹��� ��������
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
	//���콺 ��ǥ�� ���ӳ� ������ ��ǥ�� ��ȯ
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
		//���ӽ��� ��ư Ŭ����
		//��� ������ �����ͼ� ���콺�� ������ �˻��ϱ�
		sf::FloatRect titlestartBounds = titlestart->GetGlobalBounds();
		if (titlestartBounds.contains(worldMousePos))
		{
			SCENE_MGR.ChangeScene(SceneIds::SceneGame);
		}

		//�ɼǹ�ư Ŭ����
		//��� ������ �����ͼ� ���콺�� ������ �˻��ϱ�
		sf::FloatRect titleoptionBounds = titleoption->GetGlobalBounds();
		if (titleoptionBounds.contains(worldMousePos))
		{
			if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
			{
				//�簢�� ����ϰ�
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
