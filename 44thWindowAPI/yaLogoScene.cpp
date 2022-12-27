#include "yaLogoScene.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"
#include "yaObject.h"
#include "Logo.h"
#include "LogoPlayerObject.h"
#include "yaToolScene.h"
#include "yaUIManager.h"

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
		//bg->Initialize();
		AddGameObject(bg, eColliderLayer::BackGround);

		Logo* logo = new Logo();
		logo->SetImage(L"logo", L"Logo.bmp");
		logo->Initialize();
		AddGameObject(logo, eColliderLayer::UI);

		ya::object::Instantiate<LogoPlayerObject>(eColliderLayer::UI);

		UIManager::Push(eUIType::LogoButton1);
		UIManager::Push(eUIType::LogoButton2);
		UIManager::Push(eUIType::LogoButton3);
		UIManager::Push(eUIType::LogoButton4);
		UIManager::Push(eUIType::LogoButton5);
		UIManager::Push(eUIType::LogoButton6);
		//UIManager::Push(eUIType::INVENTORY);

		//여기에 미리 불러온 툴씬 넣기
		/*ya::Scene* scene = ya::SceneManager::GetScene(eSceneType::Tool);
		ya::ToolScene* toolScene = dynamic_cast<ya::ToolScene*>(scene);
		toolScene->LoadTilePalette(L"..\\Resources\\TileSaveFiles\\Test");*/
		
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
		/*UIManager::Push(eUIType::LogoButton1);
		UIManager::Push(eUIType::LogoButton2);
		UIManager::Push(eUIType::LogoButton3);*/
	}
	void LogoScene::Exit()
	{
		UIManager::Pop(eUIType::LogoButton1);
		UIManager::Pop(eUIType::LogoButton2);
		UIManager::Pop(eUIType::LogoButton3);
		UIManager::Pop(eUIType::LogoButton4);
		UIManager::Pop(eUIType::LogoButton5);
		UIManager::Pop(eUIType::LogoButton6);

	}
}