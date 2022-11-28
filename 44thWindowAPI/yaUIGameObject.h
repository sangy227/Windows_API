#pragma once
#include "yaGameObject.h"

namespace ya {
	class Animator;
	class Image;
	class UIGameObject : public GameObject
	{
	public:
		UIGameObject();
		~UIGameObject();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
	private:
		AniMator* mAnimator;
		Image* mImages[20];
	};
}

