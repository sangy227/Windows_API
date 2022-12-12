
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class Gerbil_Ruffian : public GameObject
	{
	public:
		Gerbil_Ruffian();
		Gerbil_Ruffian(Vector2 position);
		~Gerbil_Ruffian();

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