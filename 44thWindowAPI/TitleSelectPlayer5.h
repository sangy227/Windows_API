
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class TitleSelectPlayer5 : public GameObject
	{
	public:
		TitleSelectPlayer5();
		~TitleSelectPlayer5();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
	private:
		AniMator* mAnimator;
		Image* mImages[20];
	};
}