#include "yaGameObject.h"
#include "yaRigidbody.h"
#include "yaTime.h"


namespace ya {
	Rigidbody::Rigidbody()
		: Component(eComponentType::Rigidbody)
		, mMass(1.0f)
		, mFriction(100.0f)
	{
		mLimitVelocity.x = 200.f;
		mLimitVelocity.y = 1000.f;
		mbGround = true;
		mGravity = Vector2(0.0f, 800.0f);
	}

	Rigidbody::~Rigidbody()
	{

	}

	void Rigidbody::Tick()
	{
		//이동
		// F = M x A
		// A = F / M
		mAccelation = mForce / mMass;

		// 속도에 가속도를 더한다
		mVelocity += mAccelation * Time::DeltaTime();

		if (mbGround)
		{
			// 땅위에 있을때
			Vector2 gravity = mGravity;
			gravity.Normalize();
			float dot = ya::math::Dot(mVelocity, gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
			// 공중에 있을 때
			mVelocity += mGravity * Time::DeltaTime();
		}


		// 최대 속도 제한
		Vector2 gravity = mGravity;
		gravity.Normalize();
		float dot = ya::math::Dot(mVelocity, gravity);
		gravity = gravity * dot;

		Vector2 sideVelocity = mVelocity - gravity;
		if (mLimitVelocity.y < gravity.Length())
		{
			gravity.Normalize();
			gravity *= mLimitVelocity.y;
		}

		if (mLimitVelocity.x < sideVelocity.Length())
		{
			sideVelocity.Normalize();
			sideVelocity *= mLimitVelocity.x;
		}
		mVelocity = gravity + sideVelocity;

		//마찰력 조건 ( 적용된 힘이 없고, 속도가 0 이 아닐 떄)
		if (!(mVelocity == Vector2::Zero))
		{
			// 속도에 반대 방향으로 마찰력을 적용
			Vector2 friction = -mVelocity;
			friction = friction.Normalize() * mFriction * mMass * Time::DeltaTime();

			// 마찰력으로 인한 속도 감소량이 현재 속도보다 더 큰 경우
			if (mVelocity.Length() < friction.Length())
			{
				// 속도를 0 로 만든다.
				mVelocity = Vector2(0.f, 0.f);
			}
			else
			{
				// 속도에서 마찰력으로 인한 반대방향으로 속도를 차감한다.
				mVelocity += friction;
			}
		}

		// 속도에 맞게 물체를 이동시킨다.
		Vector2 pos = GetOwner()->GetPos();
		pos = pos + mVelocity * Time::DeltaTime();
		GetOwner()->SetPos(pos);
		mForce.clear();
	}

	void Rigidbody::Render(HDC hdc)
	{

	}

	void Rigidbody::AddForce(Vector2 force)
	{
		mForce += force;
	}
}
