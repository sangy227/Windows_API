
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class boastful_spellsword : public GameObject
	{
	public:
		boastful_spellsword();
		boastful_spellsword(Vector2 position);
		~boastful_spellsword();

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