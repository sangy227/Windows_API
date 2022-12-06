#include "badgerKing.h"

#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

namespace ya {
	badgerKing::badgerKing()
	{
		SetName(L"badgerKing");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"badgerKing", L"..\\Resources\\Image\\Monster\\badgerKing.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	badgerKing::badgerKing(Vector2 position)
	{
		SetName(L"badgerKing");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"badgerKing", L"..\\Resources\\Image\\Monster\\badgerKing.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	badgerKing::~badgerKing()
	{
	}
	void badgerKing::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void badgerKing::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void badgerKing::OnCollisionEnter(Collider* other)
	{
	}
	void badgerKing::OnCollisionStay(Collider* other)
	{
	}
	void badgerKing::OnCollisionExit(Collider* other)
	{
	}
}