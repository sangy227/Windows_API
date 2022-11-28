
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class TitleSelectPlayer4 : public GameObject
	{
	public:
		TitleSelectPlayer4();
		~TitleSelectPlayer4();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
	private:
		AniMator* mAnimator;
		Image* mImages[20];
	};
}