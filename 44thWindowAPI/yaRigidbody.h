#pragma once
#include "yaComponent.h"

namespace ya {
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void AddForce(Vector2 force);
		void SetMass(float mass) { mMass = mass; }
	private:
		//힘과 마찰력을 이용한 이동이 추가
		float mMass;
		float mFriction;
		
		Vector2 mForce;
		Vector2 mVelocity;
		Vector2 mAccelation;

		//중력을 이용한 점프
		Vector2 mGravity;
		bool mbGround;
		Vector2 mLimitVelocity;
	};
}

