#include "salamander.h"

#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

namespace ya {
	salamander::salamander()
	{
		SetName(L"salamander");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"salamander", L"..\\Resources\\Image\\Monster\\salamander.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	salamander::salamander(Vector2 position)
	{
	}
	salamander::~salamander()
	{
	}
	void salamander::Tick()
	{
	}
	void salamander::Render(HDC hdc)
	{
	}
	void salamander::OnCollisionEnter(Collider* other)
	{
	}
	void salamander::OnCollisionStay(Collider* other)
	{
	}
	void salamander::OnCollisionExit(Collider* other)
	{
	}
}