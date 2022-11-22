#include "yaTitleScene.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"
#include "yaPlayerSeclectUI.h"
#include "yaUIManager.h"

namespace ya {

	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		BgImageObject* bg = new BgImageObject();
		bg->SetImage(L"TitleBG", L"bg1.bmp");
		bg->Initialize();

		AddGameObject(bg,eColliderLayer::BackGround);
	}
	void TitleScene::Tick()
	{
		Scene::Tick();

		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::PlayOne);
		}
		if (KEY_DOWN(eKeyCode::I)) 
		{
			PlayerSeclectUI* PlayerSelecetUI = new PlayerSeclectUI();
			Scene* playScene = SceneManager::GetPlayScene();
			playScene->AddGameObject(PlayerSelecetUI, eColliderLayer::UI);
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		//wchar_t szFloat[50] = {};
		//swprintf_s(szFloat, 50, L"Title Scene");
		//int strLen = wcsnlen_s(szFloat, 50);
		//TextOut(hdc, 10, 30, szFloat, strLen);

	}
	void TitleScene::Enter()
	{
		UIManager::Push(eUIType::Mc_Info);
		//UIManager::Push(eUIType::Tote_Info);
		//UIManager::Push(eUIType::Cr8_Info);
		//UIManager::Push(eUIType::Setchel_Info);

		UIManager::Push(eUIType::TitleDefault);
	}
	void TitleScene::Exit()
	{
		UIManager::Pop(eUIType::Mc_Info);
		//UIManager::Pop(eUIType::Tote_Info);
		//UIManager::Pop(eUIType::Cr8_Info);
		//UIManager::Pop(eUIType::Setchel_Info);

		UIManager::Pop(eUIType::TitleDefault);
	}
}