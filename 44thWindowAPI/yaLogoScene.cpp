#include "yaLogoScene.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"


namespace ya {
	
	LogoScene::LogoScene()
	{
	}

	LogoScene::~LogoScene()
	{
	}

	void LogoScene::Initialize()
	{
		/*BgImageObject* bg = new BgImageObject();
		bg->SetImage(L"LogoBG", L"LogoBG.bmp");
		bg->Initialize();
		AddGameObject(bg, eColliderLayer::BackGround);*/

		AddGameObject(new Player(),eColliderLayer::Player);
		AddGameObject(new Monster(), eColliderLayer::Monster);
		
		Monster* pMonster = new Monster();
		pMonster->SetPos({ 1600 / 2 + 130, 300 / 2 });

		AddGameObject(pMonster, eColliderLayer::Monster);


		CollisionManager::SetLayer(eColliderLayer::Player, eColliderLayer::Monster, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::player_ProjectTile, true);
	}

	void LogoScene::Tick()
	{
		//오브젝트 Tick 을 호출
		Scene::Tick();

		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::Title);
		}
	}

	void LogoScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"Logo Scene.bmp");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strLen);
		
	}
	void LogoScene::Enter()
	{
	}
	void LogoScene::Exit()
	{
	}
}