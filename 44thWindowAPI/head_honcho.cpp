#include "head_honcho.h"

#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

namespace ya {
	head_honcho::head_honcho()
	{
		SetName(L"head_honcho");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"head_honcho", L"..\\Resources\\Image\\Monster\\head_honcho.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	head_honcho::head_honcho(Vector2 position)
	{
		SetName(L"head_honcho");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"head_honcho", L"..\\Resources\\Image\\Monster\\head_honcho.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	head_honcho::~head_honcho()
	{
	}
	void head_honcho::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void head_honcho::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void head_honcho::OnCollisionEnter(Collider* other)
	{
	}
	void head_honcho::OnCollisionStay(Collider* other)
	{
	}
	void head_honcho::OnCollisionExit(Collider* other)
	{
	}
}