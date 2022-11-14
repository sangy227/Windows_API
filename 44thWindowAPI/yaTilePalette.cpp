#include "yaTilePalette.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaObject.h"
#include "yaToolScene.h"
#include "yaInput.h"
#include <commdlg.h>

namespace ya {
	TilePalette::TilePalette()
	{
		mImage
			= Resources::Load<Image>(L"TileAtlas", L"..\\Resources\\Image\\Tile.bmp");
	}
	TilePalette::~TilePalette()
	{
	}
	void TilePalette::Tick()
	{
		if (KEY_PREESE(eKeyCode::LBTN) || KEY_DOWN(eKeyCode::LBTN))
		{
			if (GetFocus())
			{
				ya::Vector2  mousePos = ya::Input::GetMousePos();

				int y = mousePos.y / (TILE_SIZE * TILE_SCALE);
				int x = mousePos.x / (TILE_SIZE * TILE_SCALE);

				ya::Scene* scene = ya::SceneManager::GetPlayScene();
				ya::ToolScene* toolScene = dynamic_cast<ya::ToolScene*>(scene);
				UINT index = toolScene->GetTileIndex();

				CrateTile(index, Vector2(x, y));
			}
		}
	}
	void TilePalette::Render(HDC hdc)
	{

	}



	void TilePalette::CrateTile(UINT index, Vector2 indexPos)
	{
		TileID key;
		key.left = indexPos.x;
		key.right = indexPos.y;

		std::unordered_map<UINT64, Tile*>::iterator iter = mTiles.find(key.ID);
		if (iter != mTiles.end())
		{
			iter->second->SetIndex(index);
		}

		Vector2 objectPos = indexPos * (TILE_SIZE * TILE_SCALE);

		Tile* tile = object::Instantiate<Tile>(objectPos, eColliderLayer::Tile);
		tile->Initiailize(mImage, index);

		mTiles.insert(std::make_pair(key.ID, tile));
	}
	void TilePalette::Save()
	{
		// open a file name
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0*.tile\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetSaveFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"wb");
		if (pFile == nullptr)
			return;

		std::unordered_map<UINT64, Tile*>::iterator iter = mTiles.begin();
		for (; iter != mTiles.end(); ++iter)
		{
			int tileIndex = (*iter).second->GetIndex();
			fwrite(&tileIndex, sizeof(int), 1, pFile);

			TileID id;
			id.ID = (*iter).first;
			fwrite(&id.ID, sizeof(UINT64), 1, pFile);
		}

		fclose(pFile);

	}
	void TilePalette::Load()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetOpenFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"rb");
		if (pFile == nullptr)
			return;

		while (true)
		{
			int tileIndex = 0;
			TileID id;

			if (fread(&tileIndex, sizeof(int), 1, pFile) == NULL)
				break;

			if (fread(&id.ID, sizeof(UINT64), 1, pFile) == NULL)
				break;

			CrateTile(tileIndex, Vector2(id.left, id.right));
		}

		fclose(pFile);
	}
	void TilePalette::Load(const std::wstring& path)
	{
		FILE* pFile = nullptr;
		_wfopen_s(&pFile, path.c_str(), L"rb");
		if (pFile == nullptr)
			return;

		while (true)
		{
			int tileIndex = 0;
			TileID id;

			if (fread(&tileIndex, sizeof(int), 1, pFile) == NULL)
				break;

			if (fread(&id.ID, sizeof(UINT64), 1, pFile) == NULL)
				break;

			CrateTile(tileIndex, Vector2(id.left, id.right));
		}

		fclose(pFile);
	}
}