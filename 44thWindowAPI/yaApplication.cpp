#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaTime.h"
#include "yaInput.h"
namespace ya {
	//Application Application::mInstance;

	void Application::Initialize(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd);
		
		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
	}

	void Application::Tick()
	{
		Time::Tick();
		Input::Tick();

		SceneManager::Tick();
		SceneManager::Render(mWindowData.hdc);

		Time::Render(mWindowData.hdc);
		Input::Render(mWindowData.hdc);

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
