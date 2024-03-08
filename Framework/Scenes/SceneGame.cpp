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
	AddGo(background);

	//
	worldLeft = background->GetGlobalBounds().left;
	worldRight = worldLeft + background->GetGlobalBounds().width;


	//게임 씬에서 플레이어 건물 출력
	Playerbuilding = new SpriteGo("BackGround");
	Playerbuilding->SetTexture("graphics/Age1.png");
	Playerbuilding->SetPosition({ -730.f, 150.f });
	Playerbuilding->SetOrigin(Origins::MC);
	AddGo(Playerbuilding);

	//게임 씬에서 적군 건물 출력
	enemybuilding = new SpriteGo("BackGround");
	enemybuilding->SetTexture("graphics/Age2.png");
	enemybuilding->SetPosition({ 730.f, 150.f });
	enemybuilding->SetScale(sf::Vector2f( - 1.f, 1.f));
	enemybuilding->SetOrigin(Origins::MC);
	AddGo(enemybuilding);

	//게임 씬에서 터렛 출력 건물의 좌표를 받아서 위에 위치하게 좌표 바꾸고 싶으면 그 좌표 값에 +-
	age1Turrent1 = new SpriteGo("BackGround");
	age1Turrent1->SetTexture("graphics/age1turret1.png");
	age1Turrent1->SetPosition({ Playerbuilding->GetPosition().x + 60.f, Playerbuilding->GetPosition().y - 30.f});
	//age1Turrent1->SetPosition({ -730.f, 150.f });
	//enemybuilding->SetScale(-1.f, 1.f);
	age1Turrent1->SetOrigin(Origins::MC);
	//age1Turrent1->SetActive(false);
	AddGo(age1Turrent1);


	pauseclose = new TextGo("pauseclose");
	pauseclose->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Close", 80, sf::Color::White);
	pauseclose->SetPosition({ pauseshape.getGlobalBounds().left, pauseshape.getGlobalBounds().top });
	pauseclose->SetActive(false);
	
	hud = new UiHud("Hud");
	AddGo(hud, Ui);

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


	worldView.setSize(viewSize);
	worldView.setCenter(viewcenter);


	Scene::Enter();

	//SetStatus(Status::Playing);
	//머할지

	//prevMousPos = InputMgr::GetMousePos();
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

	//뷰의 중심을 가져옴
	sf::Vector2f currentCenter = worldView.getCenter();
	sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();

	//마우스 위치 따라 뷰 이동 //
	sf::Vector2f currMousePos = InputMgr::GetMousePos();
	sf::Vector2f worldMousePos = ScreenToWorld((sf::Vector2i)currMousePos);



	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		ispause = !ispause; // 상태 토글
	}

	//일시정지 할때 게임 진행 상황도 멈추게
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		ispause = true;

		pauseshape.setPosition({currentCenter.x + 100.f, currentCenter.y + 300.f});
		Utils::SetOrigin(pauseshape, Origins::MC);
		pauseshape.setSize({ 500.f, 300.f });
		pauseshape.setFillColor(sf::Color::Blue);
		Utils::SetOrigin(pauseshape, Origins::MC); //SetOrigin이 인자를 도형과 위치 2개 받아야함
		
		//팝업창 닫기 버튼이 없다면
		if (!pauseclose->GetActive())
		{
			pauseclose->SetActive(true);
		}

		//게임 씬내에서 팝업창 닫기가 안됩니다.
		sf::FloatRect closeBounds = pauseclose->GetGlobalBounds();
		if (closeBounds.contains(worldMousePos) && ispause)
		{
			pauseclose->SetActive(false);
		}
	}

	//Utils::SetOrigin(pauseshape, Origins::MC); 멤버에 없기떄문에



	//sf::Vector2f diff =  currMousePos - prevMousPos;
	//diff.y = 0;
	//sf::Vector2f center = worldView.getCenter();
	//center += diff;
	//worldView.setCenter(center);
	////std::cout << center.x << std::endl;

	//prevMousPos = InputMgr::GetMousePos();

	//----------------------------------화면 밖으로 뷰가 나가지 않도록 하기----------------

	//뷰좌표기준으로 한다.
	if (InputMgr::GetKey(sf::Keyboard::D))
	{
		currentCenter.x += viewMoveSpeed * dt; // 오른쪽으로 이동
		if (currentCenter.x > worldRight - worldView.getSize().x / 2)
		{
			currentCenter.x = worldRight - worldView.getSize().x / 2;
		}
	}
	// 왼쪽으로 이동하는 조건
	if (InputMgr::GetKey(sf::Keyboard::A))
	{
		currentCenter.x -= viewMoveSpeed * dt; // 왼쪽으로 이동
		if (currentCenter.x < worldLeft + worldView.getSize().x / 2)
		{
			currentCenter.x = worldLeft + worldView.getSize().x / 2;
		}
	}


	worldView.setCenter(currentCenter);

	// 변경된 뷰를 윈도우에 적용합니다.
	FRAMEWORK.GetWindow().setView(worldView);
}

void SceneGame::FixedUpdate(float dt)
{
	Scene::FixedUpdate(dt);
}

void SceneGame::AddExp(int s)
{
	this->Exp += s;
	hud->SetExp(this->Exp);
}

void SceneGame::AddMoney(int s)
{
	this->Money += s;
	hud->SetMoney(this->Money);
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);

	if (hud != nullptr)
	{
		hud->Draw(window);
	}

	//팝업창 그리기
	if (ispause )
	{
		window.draw(pauseshape);
		if (pauseclose->GetActive())
		{
			pauseclose->Draw(window);
		}
	}

	//if (!pauseclose->GetActive())
	//{
	//	window.draw(pauseshape);
	//	pauseclose->Draw(window);
	//}
}

