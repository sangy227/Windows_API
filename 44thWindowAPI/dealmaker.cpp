#include "dealmaker.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

namespace ya {
	dealmaker::dealmaker()
	{
		SetName(L"dealmaker");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"dealmaker", L"..\\Resources\\Image\\Monster\\dealmaker.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	dealmaker::dealmaker(Vector2 position)
	{
		SetName(L"dealmaker");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"dealmaker", L"..\\Resources\\Image\\Monster\\dealmaker.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	dealmaker::~dealmaker()
	{
	}
	void dealmaker::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void dealmaker::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void dealmaker::OnCollisionEnter(Collider* other)
	{
	}
	void dealmaker::OnCollisionStay(Collider* other)
	{
	}
	void dealmaker::OnCollisionExit(Collider* other)
	{
	}
}