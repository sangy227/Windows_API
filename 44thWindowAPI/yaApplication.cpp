#include "yaApplication.h"
#include "yaSceneManager.h"

namespace ya {

	
	Application Application::mInstance;

	ya::Application::Application()
	{
		mWindowData.clear();
	}

	ya::Application::~Application()
	{
		ReleaseDC(mWindowData.hWnd, mWindowData.hdc);
	}

	void ya::Application::Initialize(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd);
	}

	void ya::Application::Tick()
	{
	}

}
