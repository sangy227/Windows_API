#include "fire_gecko.h"

#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

namespace ya {
	fire_gecko::fire_gecko()
	{
		SetName(L"fire_gecko");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"fire_gecko", L"..\\Resources\\Image\\Monster\\fire_gecko.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	fire_gecko::fire_gecko(Vector2 position)
	{
		SetName(L"fire_gecko");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"fire_gecko", L"..\\Resources\\Image\\Monster\\fire_gecko.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	fire_gecko::~fire_gecko()
	{
	}
	void fire_gecko::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void fire_gecko::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void fire_gecko::OnCollisionEnter(Collider* other)
	{
	}
	void fire_gecko::OnCollisionStay(Collider* other)
	{
	}
	void fire_gecko::OnCollisionExit(Collider* other)
	{
	}
}