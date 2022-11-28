
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class TitleSelectPlayer2 : public GameObject
	{
	public:
		TitleSelectPlayer2();
		~TitleSelectPlayer2();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
	private:
		AniMator* mAnimator;
		Image* mImages[20];
	};
}