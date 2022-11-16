#include "yaPlayScene.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"
#include "yaObject.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"
#include "chicken.h"
#include "yaGround.h"

namespace ya {
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}


	void PlayScene::Initialize()
	{
		BgImageObject* bg2 = new BgImageObject();
		bg2->SetImage(L"PlayBG2", L"bg2.bmp");
		bg2->Initialize();
		AddGameObject(bg2, eColliderLayer::BackGround);

		ya::object::Instantiate<Player>(eColliderLayer::Player);

		//여기가 왜 플레이어 좌표를 수정시킬까??
		/*Ground* ground = ya::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground->SetPos(Vector2(600.0f, 900.0f));*/


		mons1 = ya::object::Instantiate<Monster>(eColliderLayer::Monster);
		mons2 = ya::object::Instantiate<Monster>(Vector2{ 1250.0f, 770.0f }, eColliderLayer::Monster);
		mons3 = ya::object::Instantiate<chicken>(Vector2{ 1430.0f, 770.0f }, eColliderLayer::Monster);

		

		/*CollisionManager::SetLayer(eColliderLayer::Player, eColliderLayer::Monster, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);*/
	}


	void PlayScene::Tick()
	{
		Scene::Tick();
		


		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::PlayTwo);
		}
		if (KEY_DOWN(eKeyCode::B))
		{

		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"Play Scene");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strLen);
	}
	void PlayScene::Enter()
	{
		CollisionManager::SetLayer(eColliderLayer::Player, eColliderLayer::Monster, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);
		CollisionManager::SetLayer(eColliderLayer::Ground, eColliderLayer::Player, true);
	}
	void PlayScene::Exit()
	{
		
	}
}