

#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class TitleSelectPlayer6 : public GameObject
	{
	public:
		TitleSelectPlayer6();
		~TitleSelectPlayer6();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
	private:
		AniMator* mAnimator;
		Image* mImages[20];
	};
}