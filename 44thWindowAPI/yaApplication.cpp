#include <Windows.h>
#include "Common.h"
#include "44thWindowAPI.h"
#include "framework.h"


#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaCollisionManager.h"
#include "yaCamera.h"
#include "yaUIManager.h"

namespace ya {
	//Application Application::mInstance;

	void Application::Initialize(WindowData data)
	{
		InitializeWindow(data);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
		UIManager::Initialize();
		Camera::Initialize();

	}

	void Application::initializeAtlasWindow(WindowData data)
	{
		mAtlasWindowData = data;
		mAtlasWindowData.hdc = GetDC(data.hWnd);
	}

	void Application::Tick()
	{
		Time::Tick();
		Input::Tick();
		

		SceneManager::Tick();
		CollisionManager::Tick();
		UIManager::Tick();
		Camera::Tick();


		//clear

		//Brush brush(mWindowData.backBuffer, mBrushes[(UINT)eBrushColor::Gray]);

		HBRUSH hPrevBrush = (HBRUSH)SelectObject(mWindowData.backBuffer, mBrushes[(UINT)eBrushColor::Gray]);
		Rectangle(mWindowData.backBuffer, -1, -1, 
			mWindowData.width + 1, mWindowData.height + 1);
		SelectObject(mWindowData.backBuffer, hPrevBrush);


		SceneManager::Render(mWindowData.backBuffer);
		UIManager::Render(mWindowData.backBuffer);
		Camera::Render(mWindowData.backBuffer);
		Time::Render(mWindowData.backBuffer);
		Input::Render(mWindowData.backBuffer);


		//bitbit 함수는 dc간에 이미지를 복사해주는 함수
		BitBlt(mWindowData.hdc, 0, 0, mWindowData.width, mWindowData.height, 
			mWindowData.backBuffer, 0, 0, SRCCOPY);

		//DetroyGameObject 삭제
		SceneManager::DetroyGameObject();
	}

	void Application::SetMenuBar(bool power)
	{
		SetMenu(mWindowData.hWnd, mMenu);

		RECT rect = { 0, 0, mWindowData.width, mWindowData.height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, power);
		// 윈도우 크기 변경
		SetWindowPos(mWindowData.hWnd,
			nullptr, 0, 0
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0
		);

		ShowWindow(mWindowData.hWnd, true);
	}


	eSceneType Application::GetPlaySceneType()
	{
		return SceneManager::GetPlaySceneType();
	}

	Application::Application()
	{
		mWindowData.clear();
	}



	Application::~Application()
	{
		SceneManager::Release();
		Resources::Release();

		ReleaseDC(mWindowData.hWnd, mWindowData.hdc);
		ReleaseDC(mWindowData.hWnd, mWindowData.backBuffer);
	}



	void Application::InitializeWindow(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hWnd);

		//비트맵 해상도를 설정하기 위한 실제 위도우 크기 계산
		RECT rect = { 0,0,mWindowData.width,mWindowData.height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		//윈도우 크기 변경
		SetWindowPos(mWindowData.hWnd,
			nullptr, 0, 0,
			rect.right - rect.left,
			rect.bottom - rect.top,
			0);

		//윈도우 그리기 보여주기
		ShowWindow(mWindowData.hWnd, true);
		mWindowData.backTexture 
			= CreateCompatibleBitmap(mWindowData.hdc, mWindowData.width, mWindowData.height);

		mWindowData.backBuffer
			= CreateCompatibleDC(mWindowData.hdc);

		HBITMAP defaultBitmap 
			= (HBITMAP)SelectObject(mWindowData.backBuffer, mWindowData.backTexture);

		DeleteObject(defaultBitmap);

		//메모리 해제 해줘야한다
		mPens[(UINT)ePenColor::Red] = CreatePen(PS_SOLID, 1, RGB(225, 0, 0));
		mPens[(UINT)ePenColor::Green] = CreatePen(PS_SOLID, 1, RGB(0, 225, 0));
		mPens[(UINT)ePenColor::Blue] = CreatePen(PS_SOLID, 1, RGB(0, 0, 225));

		mBrushes[(UINT)eBrushColor::Transparent] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
		mBrushes[(UINT)eBrushColor::Black] = (HBRUSH)GetStockObject(BLACK_BRUSH);
		mBrushes[(UINT)eBrushColor::Gray] = (HBRUSH)GetStockObject(GRAY_BRUSH);
		mBrushes[(UINT)eBrushColor::White] = (HBRUSH)GetStockObject(WHITE_BRUSH);

		mMenu = LoadMenu(nullptr, MAKEINTRESOURCEW(IDC_MY44THWINDOWAPI));
	}

	
}
