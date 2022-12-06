
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class frog_2 : public GameObject
	{
	public:
		frog_2();
		frog_2(Vector2 position);
		~frog_2();

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