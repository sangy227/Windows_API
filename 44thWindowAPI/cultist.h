
#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class cultist : public GameObject
	{
	public:
		cultist();
		cultist(Vector2 position);
		~cultist();

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