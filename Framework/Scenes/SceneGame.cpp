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
	AddGo(background, Ui);

	//���� ������ �÷��̾� �ǹ� ���
	Playerbuilding = new SpriteGo("BackGround");
	Playerbuilding->SetTexture("graphics/Age1.png");
	Playerbuilding->SetPosition({ 60.f, 150.f });
	Playerbuilding->SetOrigin(Origins::MC);
	AddGo(Playerbuilding, Ui);

	//���� ������ ���� �ǹ� ���
	enemybuilding = new SpriteGo("BackGround");
	enemybuilding->SetTexture("graphics/Age2.png");
	enemybuilding->SetPosition({ 1577.f, 0.f });
	//enemybuilding->SetScale(-1.f, 1.f);
	enemybuilding->SetOrigin(Origins::MC);
	AddGo(enemybuilding, Ui);

	//���� ������ �ͷ� ���
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

	uiView.setSize(viewSize);
	uiView.setCenter(viewcenter);

	FRAMEWORK.GetWindow().setView(uiView);

	Scene::Enter();

	//SetStatus(Status::Playing);
	//������
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

	//�Ͻ����� �Ҷ�
	if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	{
		SCENE_MGR.ChangeScene(SceneIds::Title);
		////��� ������ �����ͼ� ���콺�� ������ �˻��ϱ�
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

