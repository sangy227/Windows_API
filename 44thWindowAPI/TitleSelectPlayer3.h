#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class TitleSelectPlayer3 : public GameObject
	{
	public:
		TitleSelectPlayer3();
		~TitleSelectPlayer3();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
	private:
		AniMator* mAnimator;
		Image* mImages[20];
	};
}