#pragma once
#include "yaGameObject.h"
namespace ya {
	class AniMator;
	class Image;
	class LogoPlayerObject : public GameObject
	{
	public:
		LogoPlayerObject();
		~LogoPlayerObject();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

	private:
		Image* mImage;
		Image* mImage2;
		AniMator* mAnimator;
	};
}

