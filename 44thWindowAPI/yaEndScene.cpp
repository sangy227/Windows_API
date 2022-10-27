#include "yaEndScene.h"


namespace ya {
	EndScene::EndScene()
	{
	}

	EndScene::~EndScene()
	{
	}

	void EndScene::Initialize()
	{
	}

	void EndScene::Tick()
	{
		Scene::Tick();
	}

	void EndScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"End Scene");
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 10, 30, szFloat, strLen);
	}

	void EndScene::Enter()
	{
	}

	void EndScene::Exit()
	{
	}

}
