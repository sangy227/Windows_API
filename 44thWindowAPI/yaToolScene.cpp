#include "framework.h"
#include "44thWindowAPI.h"
#include "yaToolScene.h"
#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaScene.h"
#include "yaTilePalette.h"
#include "yaInput.h"
#include "yaImage.h"

namespace ya {
	ToolScene::ToolScene()
	{
		//초기화 만들기
		mTilePalette = new TilePalette();

	}
	ToolScene::~ToolScene()
	{
		delete mTilePalette;
	}

	void ToolScene::Initialize()
	{

	}
	void ToolScene::Tick()
	{
		//추가
		Scene::Tick();

		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::Logo);
		}

	}
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		WindowData mainWindow = Application::GetInstance().GetWindowData();

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(05, 200, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);


		//여기 변경

		int maxRow = mainWindow.height / TILE_SIZE + 1;
		for (size_t i = 0; i < maxRow; i++)
		{
			MoveToEx(hdc, 0, TILE_SIZE*i, nullptr);
			LineTo(hdc, mainWindow.width, TILE_SIZE * i);
		}

		int maxColumn = mainWindow.width / TILE_SIZE + 1;
		for (size_t i = 0; i < maxColumn; i++)
		{
			MoveToEx(hdc, TILE_SIZE * i, 0, nullptr);
			LineTo(hdc, TILE_SIZE * i, mainWindow.height);
		}

		

		(HPEN)SelectObject(hdc, oldPen);
		DeleteObject(redPen);


	}
	void ToolScene::Enter()
	{
		Application::GetInstance().SetMenuBar(true);

	}
	void ToolScene::Exit()
	{

	}
}

LRESULT CALLBACK AtlasWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        WindowData windowData
            = ya::Application::GetInstance().GetWindowData();


        WindowData atlasWindowData
            = ya::Application::GetInstance().GetAtlasWindowData();

        ya::Scene* scene = ya::SceneManager::GetPlayScene();
        ya::ToolScene* toolScene = dynamic_cast<ya::ToolScene*>(scene);

        ya::Image* atlas = toolScene->GetAtalasImage();

        RECT rect = { 0, 0, atlas->GetWidth(), atlas->GetHeight() };
        //AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, true);
        SetWindowPos(hWnd, nullptr, windowData.width, 0, atlas->GetWidth(), atlas->GetHeight(), 0);

        //SetWindowPos(atlasWindowData.hWnd
        //    , nullptr, 1600, 0
        //    , rect.right - rect.left
        //    , rect.bottom - rect.top
        //    , 0);

        ShowWindow(hWnd, true);
        UpdateWindow(hWnd);

    }
    break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 메뉴 선택을 구문 분석합니다:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        WindowData atlasWindowData
            = ya::Application::GetInstance().GetAtlasWindowData();

        ya::Scene* scene = ya::SceneManager::GetPlayScene();
        ya::ToolScene* toolScene = dynamic_cast<ya::ToolScene*>(scene);

        ya::Image* atlas = toolScene->GetAtalasImage();

        ya::Vector2 pos(ya::Vector2::Zero);
        TransparentBlt(hdc, pos.x, pos.y
            , atlas->GetWidth(), atlas->GetHeight()
            , atlas->GetDC(), 0, 0, atlas->GetWidth(), atlas->GetHeight()
            , RGB(255, 0, 255));


        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        //KillTimer(hWnd, 0);
    }
    break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}