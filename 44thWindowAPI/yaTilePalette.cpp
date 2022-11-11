
#include "yaTilePalette.h"
#include "yaImage.h"
#include "yaResources.h"
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
		//추가
	}
	void TilePalette::Render(HDC hdc)
	{
	}
	void TilePalette::CrateTile(UINT index, Vector2 pos)
	{
		/*
		* //여기변경
		std::unordered_map<UINT64, Tile*>::iterator iter = mTiles.find(key.ID);

		if (iter == mTiles.end())
		{
			iter->second->SetIndex(index);
		}*/

		//여기 추가
	}
}