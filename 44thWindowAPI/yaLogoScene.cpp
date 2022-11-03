#include "yaLogoScene.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"
#include "yaObject.h"



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


		ya::object::Instantiate<Player>(eColliderLayer::Player);
		mons[0] = ya::object::Instantiate<Monster>(eColliderLayer::Monster);
		mons[1] = ya::object::Instantiate<Monster>(Vector2{ 1600 / 2 + 130, 300 / 2 }, eColliderLayer::Monster);


		CollisionManager::SetLayer(eColliderLayer::Player, eColliderLayer::Monster, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);
	}

	void LogoScene::Tick()
	{
		//오브젝트 Tick 을 호출
		Scene::Tick();

		//몇초후에 사라진다
		//ya::object::Destroy(mons[0], 3.0f);

		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::Title);
			
		}
		if (KEY_DOWN(eKeyCode::M))
		{
			ya::object::Destroy(mons[0]);
			ya::object::Destroy(mons[1]);
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