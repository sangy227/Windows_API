#include "yaPlayScene4.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"
#include "yaObject.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"
#include "chicken.h"


namespace ya {
	PlayScene4::PlayScene4()
	{
	}
	PlayScene4::~PlayScene4()
	{
	}


	void PlayScene4::Initialize()
	{
		BgImageObject* bg5 = new BgImageObject();
		bg5->SetImage(L"PlayBG5", L"bg5.bmp");
		bg5->Initialize();
		AddGameObject(bg5, eColliderLayer::BackGround);

		ya::object::Instantiate<Player>(eColliderLayer::Player);
		mons1 = ya::object::Instantiate<Monster>(eColliderLayer::Monster);
		mons2 = ya::object::Instantiate<Monster>(Vector2{ 1250.0f, 770.0f }, eColliderLayer::Monster);
		mons3 = ya::object::Instantiate<chicken>(Vector2{ 1430.0f, 770.0f }, eColliderLayer::Monster);



		/*CollisionManager::SetLayer(eColliderLayer::Player, eColliderLayer::Monster, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);*/
	}


	void PlayScene4::Tick()
	{
		Scene::Tick();



		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::End);
		}
		if (KEY_DOWN(eKeyCode::B))
		{

		}
	}
	void PlayScene4::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"Play Scene4");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strLen);
	}
	void PlayScene4::Enter()
	{
		CollisionManager::SetLayer(eColliderLayer::Player, eColliderLayer::Monster, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);
	}
	void PlayScene4::Exit()
	{
	}
}