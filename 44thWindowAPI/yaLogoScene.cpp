#include "yaLogoScene.h"
#include "yaPlayer.h"
#include "yaResource.h"
#include "yaResources.h"


namespace ya {
	
	LogoScene::LogoScene()
	{
	}

	LogoScene::~LogoScene()
	{
	}

	void LogoScene::Initialize()
	{
		AddGameObject(new Player());
	}

	void LogoScene::Tick()
	{
		Scene::Tick();
	}

	void LogoScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		
		Logo = Resources::Load<Image>(L"Logo02", L"..\\Resources\\Image\\Logo02.bmp");
		/*BitBlt(hdc, 360, 80, Logo->GetWidth(), Logo->GetHeight(),
			Logo->GetDC(), 0, 0, SRCCOPY);*/

		TransparentBlt(hdc, 360, 80
			, Logo->GetWidth(), Logo->GetHeight()
			, Logo->GetDC(), 0, 0, Logo->GetWidth(), Logo->GetHeight()
			, RGB(255, 255, 255));
		
	}
}