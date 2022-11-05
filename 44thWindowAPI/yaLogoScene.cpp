#include "yaLogoScene.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"
#include "yaObject.h"
#include "Logo.h"


namespace ya {
	
	LogoScene::LogoScene()
	{
	}

	LogoScene::~LogoScene()
	{
	}

	void LogoScene::Initialize()
	{
		BgImageObject* bg = new BgImageObject();
		bg->SetImage(L"LogoBG", L"bg1.bmp");
		bg->Initialize();
		AddGameObject(bg, eColliderLayer::BackGround);

		Logo* logo = new Logo();
		logo->SetImage(L"logo", L"Logo.bmp");
		logo->Initialize();
		AddGameObject(logo, eColliderLayer::UI);


		
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