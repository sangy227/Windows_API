#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class bandit_lord : public GameObject
	{
	public:
		bandit_lord();
		bandit_lord(Vector2 position);
		~bandit_lord();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other) override;
		virtual void OnCollisionExit(Collider* other) override;

		int GetHp() { return mHP; }
	private:
		int mHP;
		Image* mImage;
		AniMator* mAnimator;
	};
}