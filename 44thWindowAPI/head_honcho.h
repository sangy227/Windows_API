
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class head_honcho : public GameObject
	{
	public:
		head_honcho();
		head_honcho(Vector2 position);
		~head_honcho();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

	private:
		Image* mImage;
		AniMator* mAnimator;
	};
}