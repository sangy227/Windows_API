
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class Feral_Badger : public GameObject
	{
	public:
		Feral_Badger();
		Feral_Badger(Vector2 position);
		~Feral_Badger();

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