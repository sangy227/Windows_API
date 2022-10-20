#include "yaApplication.h"
#include "yaSceneManager.h"

namespace ya {
	//Application Application::mInstance;

	void Application::Initialize(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd);
		
		SceneManager::Initialize();
	}

	void Application::Tick()
	{
		SceneManager::Tick();
		SceneManager::Render(mWindowData.hdc);
	}


	Application::Application()
	{
		mWindowData.clear();
	}

	Application::~Application()
	{
		SceneManager::Release();

		ReleaseDC(mWindowData.hWnd, mWindowData.hdc);
	}

	
}
