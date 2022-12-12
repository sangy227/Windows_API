#include "Gerbil_Ruffian.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

namespace ya {
	Gerbil_Ruffian::Gerbil_Ruffian()
	{
		SetName(L"Gerbil_Ruffian");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Gerbil_Ruffian", L"..\\Resources\\Image\\Monster\\Gerbil_Ruffian.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	Gerbil_Ruffian::Gerbil_Ruffian(Vector2 position)
	{
		SetName(L"Gerbil_Ruffian");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Gerbil_Ruffian", L"..\\Resources\\Image\\Monster\\Gerbil_Ruffian.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	Gerbil_Ruffian::~Gerbil_Ruffian()
	{
	}
	void Gerbil_Ruffian::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void Gerbil_Ruffian::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Gerbil_Ruffian::OnCollisionEnter(Collider* other)
	{
	}
	void Gerbil_Ruffian::OnCollisionStay(Collider* other)
	{
	}
	void Gerbil_Ruffian::OnCollisionExit(Collider* other)
	{
	}
}