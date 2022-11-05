#include "yaPlayScene3.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"
#include "yaObject.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"
#include "chicken.h"


namespace ya {
	PlayScene3::PlayScene3()
	{
	}
	PlayScene3::~PlayScene3()
	{
	}


	void PlayScene3::Initialize()
	{
		BgImageObject* bg4 = new BgImageObject();
		bg4->SetImage(L"PlayBG4", L"bg4.bmp");
		bg4->Initialize();
		AddGameObject(bg4, eColliderLayer::BackGround);

		ya::object::Instantiate<Player>(eColliderLayer::Player);
		mons1 = ya::object::Instantiate<Monster>(eColliderLayer::Monster);
		mons2 = ya::object::Instantiate<Monster>(Vector2{ 1250.0f, 770.0f }, eColliderLayer::Monster);
		mons3 = ya::object::Instantiate<chicken>(Vector2{ 1430.0f, 770.0f }, eColliderLayer::Monster);



		CollisionManager::SetLayer(eColliderLayer::Player, eColliderLayer::Monster, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);
	}


	void PlayScene3::Tick()
	{
		Scene::Tick();



		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::PlayFour);
		}
		if (KEY_DOWN(eKeyCode::B))
		{

		}
	}
	void PlayScene3::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"Play Scene3");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strLen);
	}
	void PlayScene3::Enter()
	{
	}
	void PlayScene3::Exit()
	{
	}
}
