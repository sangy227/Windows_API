#include "yaPlayScene2.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"
#include "yaObject.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"
#include "chicken.h"


namespace ya {
	PlayScene2::PlayScene2()
	{
	}
	PlayScene2::~PlayScene2()
	{
	}


	void PlayScene2::Initialize()
	{
		BgImageObject* bg3 = new BgImageObject();
		bg3->SetImage(L"PlayBG3", L"bg3.bmp");
		bg3->Initialize();
		AddGameObject(bg3, eColliderLayer::BackGround);

		ya::object::Instantiate<Player>(eColliderLayer::Player);
		mons1 = ya::object::Instantiate<Monster>(eColliderLayer::Monster);
		mons2 = ya::object::Instantiate<Monster>(Vector2{ 1250.0f, 770.0f }, eColliderLayer::Monster);
		mons3 = ya::object::Instantiate<chicken>(Vector2{ 1430.0f, 770.0f }, eColliderLayer::Monster);



		/*CollisionManager::SetLayer(eColliderLayer::Player, eColliderLayer::Monster, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);*/
	}


	void PlayScene2::Tick()
	{
		Scene::Tick();



		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::PlayThree);
		}
		if (KEY_DOWN(eKeyCode::B))
		{

		}
	}
	void PlayScene2::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"Play Scene2");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strLen);
	}
	void PlayScene2::Enter()
	{
		CollisionManager::SetLayer(eColliderLayer::Player, eColliderLayer::Monster, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);
	}
	void PlayScene2::Exit()
	{
		CollisionManager::SetLayer(eColliderLayer::Player, eColliderLayer::Monster, false);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, false);
	}
}
