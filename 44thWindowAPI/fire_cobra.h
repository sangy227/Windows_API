
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class fire_cobra : public GameObject
	{
	public:
		fire_cobra();
		fire_cobra(Vector2 position);
		~fire_cobra();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;
		int GetHp() { return mHP; }
		void SetHp(int hp) { mHP = hp; }
	private:
		int mHP;
		Image* mImage;
		AniMator* mAnimator;
	};
}