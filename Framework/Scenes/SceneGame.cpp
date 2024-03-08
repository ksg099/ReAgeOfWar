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

void SceneGame::Init() //����
{

	//���� ������ ��� ���
	background = new SpriteGo("BackGround");
	background->SetTexture("graphics/BackGround.png");
	background->SetPosition({ 0.f, 0.f }); //�̺κ� ���� ������
	background->SetOrigin(Origins::MC);
	AddGo(background);

	//
	worldLeft = background->GetGlobalBounds().left;
	worldRight = worldLeft + background->GetGlobalBounds().width;


	//���� ������ �÷��̾� �ǹ� ���
	Playerbuilding = new SpriteGo("BackGround");
	Playerbuilding->SetTexture("graphics/Age1.png");
	Playerbuilding->SetPosition({ -730.f, 150.f });
	Playerbuilding->SetOrigin(Origins::MC);
	AddGo(Playerbuilding);

	//���� ������ ���� �ǹ� ���
	enemybuilding = new SpriteGo("BackGround");
	enemybuilding->SetTexture("graphics/Age2.png");
	enemybuilding->SetPosition({ 730.f, 150.f });
	enemybuilding->SetScale(sf::Vector2f( - 1.f, 1.f));
	enemybuilding->SetOrigin(Origins::MC);
	AddGo(enemybuilding);

	//���� ������ �ͷ� ��� �ǹ��� ��ǥ�� �޾Ƽ� ���� ��ġ�ϰ� ��ǥ �ٲٰ� ������ �� ��ǥ ���� +-
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

void SceneGame::Enter() //����
{
	//���콺 Ŀ�� �Ⱥ��̰��ϴ� �κ� �ּ�ó��
	//FRAMEWORK.GetWindow().setMouseCursorVisible(false);

	sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();

	//���� ���� ���̰� ī�޶� ȭ���� ���� �����Ŵϱ�
	//���̵� �� �������� �ҿ����̴ϱ� Y�� �״���ϰ� X�� �����ϰ� �ٲ��ָ� ��
	//���� ������ �� ������ 1280, 1024�� ������ �°� x��ǥ�� �ٲ��ָ� �ȴ�.
	sf::Vector2f viewSize = sf::Vector2f(630, 504);
	sf::Vector2f viewcenter(viewSize.x / 2, 0);


	worldView.setSize(viewSize);
	worldView.setCenter(viewcenter);


	Scene::Enter();

	//SetStatus(Status::Playing);
	//������

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

	//���� �߽��� ������
	sf::Vector2f currentCenter = worldView.getCenter();
	sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();

	//���콺 ��ġ ���� �� �̵� //
	sf::Vector2f currMousePos = InputMgr::GetMousePos();
	sf::Vector2f worldMousePos = ScreenToWorld((sf::Vector2i)currMousePos);



	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		ispause = !ispause; // ���� ���
	}

	//�Ͻ����� �Ҷ� ���� ���� ��Ȳ�� ���߰�
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		ispause = true;

		pauseshape.setPosition({currentCenter.x + 100.f, currentCenter.y + 300.f});
		Utils::SetOrigin(pauseshape, Origins::MC);
		pauseshape.setSize({ 500.f, 300.f });
		pauseshape.setFillColor(sf::Color::Blue);
		Utils::SetOrigin(pauseshape, Origins::MC); //SetOrigin�� ���ڸ� ������ ��ġ 2�� �޾ƾ���
		
		//�˾�â �ݱ� ��ư�� ���ٸ�
		if (!pauseclose->GetActive())
		{
			pauseclose->SetActive(true);
		}

		//���� �������� �˾�â �ݱⰡ �ȵ˴ϴ�.
		sf::FloatRect closeBounds = pauseclose->GetGlobalBounds();
		if (closeBounds.contains(worldMousePos) && ispause)
		{
			pauseclose->SetActive(false);
		}
	}

	//Utils::SetOrigin(pauseshape, Origins::MC); ����� ���⋚����



	//sf::Vector2f diff =  currMousePos - prevMousPos;
	//diff.y = 0;
	//sf::Vector2f center = worldView.getCenter();
	//center += diff;
	//worldView.setCenter(center);
	////std::cout << center.x << std::endl;

	//prevMousPos = InputMgr::GetMousePos();

	//----------------------------------ȭ�� ������ �䰡 ������ �ʵ��� �ϱ�----------------

	//����ǥ�������� �Ѵ�.
	if (InputMgr::GetKey(sf::Keyboard::D))
	{
		currentCenter.x += viewMoveSpeed * dt; // ���������� �̵�
		if (currentCenter.x > worldRight - worldView.getSize().x / 2)
		{
			currentCenter.x = worldRight - worldView.getSize().x / 2;
		}
	}
	// �������� �̵��ϴ� ����
	if (InputMgr::GetKey(sf::Keyboard::A))
	{
		currentCenter.x -= viewMoveSpeed * dt; // �������� �̵�
		if (currentCenter.x < worldLeft + worldView.getSize().x / 2)
		{
			currentCenter.x = worldLeft + worldView.getSize().x / 2;
		}
	}


	worldView.setCenter(currentCenter);

	// ����� �並 �����쿡 �����մϴ�.
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

	//�˾�â �׸���
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

