

#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class fire_gecko : public GameObject
	{
	public:
		fire_gecko();
		fire_gecko(Vector2 position);
		~fire_gecko();

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