#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class chicken : public GameObject
	{
	public:
		chicken();
		chicken(Vector2 position);
		~chicken();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		void SetHp(int hp) { mHP = hp; }
		int GetHp() { return mHP; }
	private:
		int mHP;
		Image* mImage;
		AniMator* mAnimator;

	};
}


