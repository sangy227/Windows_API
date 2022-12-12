#include "hermit_crab_bomb.h"

#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

namespace ya {
	hermit_crab_bomb::hermit_crab_bomb()
	{
		SetName(L"hermit_crab_bomb");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"hermit_crab_bomb", L"..\\Resources\\Image\\Monster\\hermit_crab_bomb.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	hermit_crab_bomb::hermit_crab_bomb(Vector2 position)
	{
		SetName(L"hermit_crab_bomb");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"hermit_crab_bomb", L"..\\Resources\\Image\\Monster\\hermit_crab_bomb.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	hermit_crab_bomb::~hermit_crab_bomb()
	{
	}
	void hermit_crab_bomb::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void hermit_crab_bomb::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void hermit_crab_bomb::OnCollisionEnter(Collider* other)
	{
	}
	void hermit_crab_bomb::OnCollisionStay(Collider* other)
	{
	}
	void hermit_crab_bomb::OnCollisionExit(Collider* other)
	{
	}
}