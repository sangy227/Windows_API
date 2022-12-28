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

		void Player_Move(); 
		void Player_Idel(); 
		void Player_Attack();
		void Player_BowAttack();
		void Player_SearchPack();
		void Player_Map();
		void Player_hurt();
		void Player_winsmall();
		void Player_die();
		void Player_useitem();
		void Player_block();
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

