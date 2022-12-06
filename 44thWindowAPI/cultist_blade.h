

#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class cultist_blade : public GameObject
	{
	public:
		cultist_blade();
		cultist_blade(Vector2 position);
		~cultist_blade();

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