#include "healer_enemy.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

namespace ya {
	healer_enemy::healer_enemy()
	{
		SetName(L"healer_enemy");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"healer_enemy", L"..\\Resources\\Image\\Monster\\healer_enemy.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	healer_enemy::healer_enemy(Vector2 position)
	{
		SetName(L"healer_enemy");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"healer_enemy", L"..\\Resources\\Image\\Monster\\healer_enemy.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	healer_enemy::~healer_enemy()
	{
	}
	void healer_enemy::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void healer_enemy::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void healer_enemy::OnCollisionEnter(Collider* other)
	{
	}
	void healer_enemy::OnCollisionStay(Collider* other)
	{
	}
	void healer_enemy::OnCollisionExit(Collider* other)
	{
	}
}