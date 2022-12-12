

#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class hermit_crab_bomb : public GameObject
	{
	public:
		hermit_crab_bomb();
		hermit_crab_bomb(Vector2 position);
		~hermit_crab_bomb();

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