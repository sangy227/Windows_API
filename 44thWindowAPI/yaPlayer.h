#pragma once
#include "yaGameObject.h"

namespace ya {
	class AniMator;
	class Image;
	class Player : public GameObject
	{
	public:
		enum class eState
		{
			Attack,
			Bow,
			Death,
		};


		Player();
		~Player();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other) override;
		virtual void OnCollisionStay(Collider* other)override;
		virtual void OnCollisionExit(Collider* other)override;
		
		void WalkComplete();

		void SetHp(int hp) { mHp = hp; }
		int GetHp() { return mHp; }

		void Attack(); // 쿠키런 할때 볼수잇는것
	private:
		eState mState;
		float mCoff;
		float mSpeed;

		Image* mImage;
		Image* mImage2;
		Image* mImages[20];

		AniMator* mAnimator;

		float mTime;
		Vector2 mMisiileDir;

		int mAttackCount;
		int mDamageCount;
		int mHp;
	};
}	

