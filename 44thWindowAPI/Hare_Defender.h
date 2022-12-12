
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class Hare_Defender : public GameObject
	{
	public:
		Hare_Defender();
		Hare_Defender(Vector2 position);
		~Hare_Defender();

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