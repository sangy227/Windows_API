#pragma once
#include "yaTile.h"

namespace ya
{
	class Image;
	class TilePalette
	{
	public:
		TilePalette();
		~TilePalette();

		void Tick();
		void Render(HDC hdc);

		
		void CrateTile(UINT index, Vector2 indexPos);
		//void CrateTiles

		void Save();
		void Load();
		void Load(const std::wstring& path);

		Image* GetAtlasImage() { return mImage; }


	private:
		Image* mImage;
		std::unordered_map<UINT64, Tile*> mTiles;
	};
}

