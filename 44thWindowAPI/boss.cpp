#include "boss.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

namespace ya {
	boss::boss()
	{
		SetName(L"boss");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"boss", L"..\\Resources\\Image\\Monster\\boss.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(64.0f, 48.0f)
			, Vector2(-36.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	boss::boss(Vector2 position)
	{
		SetName(L"boss");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"boss", L"..\\Resources\\Image\\Monster\\boss.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(64.0f, 48.0f)
			, Vector2(-36.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	boss::~boss()
	{
	}
	void boss::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void boss::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void boss::OnCollisionEnter(Collider* other)
	{
	}
	void boss::OnCollisionStay(Collider* other)
	{
	}
	void boss::OnCollisionExit(Collider* other)
	{
	}
}