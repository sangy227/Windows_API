#include "hawk_knight.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

namespace ya {
	hawk_knight::hawk_knight()
	{
		SetName(L"hawk_knight");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"hawk_knight", L"..\\Resources\\Image\\Monster\\º¯°æ__.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);
		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	hawk_knight::hawk_knight(Vector2 position)
	{
		SetName(L"hawk_knight");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"hawk_knight", L"..\\Resources\\Image\\Monster\\hawk_knight.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	hawk_knight::~hawk_knight()
	{
	}
	void hawk_knight::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void hawk_knight::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void hawk_knight::OnCollisionEnter(Collider* other)
	{
	}
	void hawk_knight::OnCollisionStay(Collider* other)
	{
	}
	void hawk_knight::OnCollisionExit(Collider* other)
	{
	}
}