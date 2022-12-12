
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class legman : public GameObject
	{
	public:
		legman();
		legman(Vector2 position);
		~legman();

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