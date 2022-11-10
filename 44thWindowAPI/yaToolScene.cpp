#include "yaToolScene.h"
#include "yaApplication.h"

namespace ya {
	ToolScene::ToolScene()
	{
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

	}
	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		WindowData mainWindow = Application::GetInstance().GetWindowData();

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(05, 200, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

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