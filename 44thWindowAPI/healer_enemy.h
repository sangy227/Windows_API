
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class healer_enemy : public GameObject
	{
	public:
		healer_enemy();
		healer_enemy(Vector2 position);
		~healer_enemy();

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