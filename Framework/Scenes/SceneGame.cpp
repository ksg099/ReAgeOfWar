#include "pch.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "PlayerBuilding.h"
#include "EnemyBuilding.h"
#include "Turret.h"
#include "UiHud.h"

SceneGame::SceneGame(SceneIds id) : Scene(id)
{
}

void SceneGame::SetStatus(Status newStatus)
{
	//currentStatus = newStatus;
	//switch (currentStatus)
	//{
	//case SceneGame::Status::Title:
	//	FRAMEWORK.SetTimeScale(0.f);
	//	break;
	//case SceneGame::Status::Playing:
	//	FRAMEWORK.SetTimeScale(1.f);
	//	break;
	//case SceneGame::Status::NextWave:
	//	FRAMEWORK.SetTimeScale(0.f);
	//	break;
	//case SceneGame::Status::GameOver:
	//	FRAMEWORK.SetTimeScale(0.f);
	//	break;
	//case SceneGame::Status::Pause:
	//	FRAMEWORK.SetTimeScale(0.f);
	//	break;
	//}
}

void SceneGame::Init() //차이
{

	//게임 씬에서 배경 출력
	background = new SpriteGo("BackGround");
	background->SetTexture("graphics/BackGround.png");
	background->SetPosition({ 0.f, 0.f }); //이부분 문제 같은데
	background->SetOrigin(Origins::MC);
	AddGo(background, Ui);

	//게임 씬에서 플레이어 건물 출력
	Playerbuilding = new SpriteGo("BackGround");
	Playerbuilding->SetTexture("graphics/Age1.png");
	Playerbuilding->SetPosition({ 60.f, 150.f });
	Playerbuilding->SetOrigin(Origins::MC);
	AddGo(Playerbuilding, Ui);

	//게임 씬에서 적군 건물 출력
	enemybuilding = new SpriteGo("BackGround");
	enemybuilding->SetTexture("graphics/Age2.png");
	enemybuilding->SetPosition({ 1577.f, 0.f });
	//enemybuilding->SetScale(-1.f, 1.f);
	enemybuilding->SetOrigin(Origins::MC);
	AddGo(enemybuilding, Ui);

	//게임 씬에서 터렛 출력
	age1Turrent1 = new SpriteGo("BackGround");
	age1Turrent1->SetTexture("graphics/turrets/age1turrent1.png");
	age1Turrent1->SetPosition({ 1000.f, 150.f });
	//enemybuilding->SetScale(-1.f, 1.f);
	age1Turrent1->SetOrigin(Origins::MC);
	//age1Turrent1->SetActive(false);
	AddGo(age1Turrent1, Ui);


	//hud = new UiHud("Hud");
	//AddGo(hud, Scene::Layers::Ui);

	Scene::Init();
}

void SceneGame::Release()
{
}

void SceneGame::Enter() //차이
{
	//마우스 커서 안보이게하는 부분 주석처리
	//FRAMEWORK.GetWindow().setMouseCursorVisible(false);

	sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();

	//지금 내가 보이고 카메라 화면을 띄우고 싶은거니까
	//사이드 뷰 게임으로 할예정이니까 Y는 그대로하고 X만 적절하게 바꿔주면 됨
	//현재 윈도우 뷰 사이즈 1280, 1024의 비율에 맞게 x좌표도 바꿔주면 된다.
	sf::Vector2f viewSize = sf::Vector2f(630, 504);

	sf::Vector2f viewcenter(viewSize.x / 2, 0);

	uiView.setSize(viewSize);
	uiView.setCenter(viewcenter);

	FRAMEWORK.GetWindow().setView(uiView);

	Scene::Enter();

	//SetStatus(Status::Playing);
	//머할지
}

void SceneGame::Exit()
{
	Scene::Exit();
	FRAMEWORK.GetWindow().setMouseCursorVisible(true);
}

void SceneGame::Reset()
{
}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);

	//
	sf::Vector2i mousePos = sf::Mouse::getPosition(FRAMEWORK.GetWindow());
	sf::Vector2f worldMousePos = FRAMEWORK.GetWindow().mapPixelToCoords(mousePos);

	//일시정지 할때
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneIds::Title);
		////경계 범위를 가져와서 마우스가 있을때 검사하기
		//sf::FloatRect titleoptionBounds = titleoption->GetGlobalBounds();
		//if (titleoptionBounds.contains(worldMousePos))
		//{
		//	if (optionclose == Active(true)
		//	{
		//		optionclose->SetActive(true);
		//	}
		//	else
		//	{
		//		optionclose->SetActive(false);
		//	}
		//}
	}
}

void SceneGame::FixedUpdate(float dt)
{
	Scene::FixedUpdate(dt);
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);

}

