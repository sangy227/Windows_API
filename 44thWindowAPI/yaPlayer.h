#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other)override;
		virtual void OnCollisionExit(Collider* other)override;
		
		void WalkComplete();
	private:
		float mSpeed;
		Image* mImage;
		Image* mImage2;
		AniMator* mAnimator;
	};
}	

