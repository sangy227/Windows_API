
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
	}
	void TilePalette::Render(HDC hdc)
	{
	}
}