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

		//void CrateTile
		//void CrateTiles

		//void Save
		//void Load

		Image* GetAtlasImage() { return mImage; }


	private:
		Image* mImage;
	};
}

