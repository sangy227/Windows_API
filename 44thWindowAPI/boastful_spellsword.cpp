#include "boastful_spellsword.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

namespace ya {
	boastful_spellsword::boastful_spellsword()
	{
		SetName(L"boastful_spellsword");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"boastful_spellsword", L"..\\Resources\\Image\\Monster\\boastful_spellsword.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	boastful_spellsword::boastful_spellsword(Vector2 position)
	{
		SetName(L"boastful_spellsword");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"boastful_spellsword", L"..\\Resources\\Image\\Monster\\boastful_spellsword.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	boastful_spellsword::~boastful_spellsword()
	{
	}
	void boastful_spellsword::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void boastful_spellsword::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void boastful_spellsword::OnCollisionEnter(Collider* other)
	{
	}
	void boastful_spellsword::OnCollisionStay(Collider* other)
	{
	}
	void boastful_spellsword::OnCollisionExit(Collider* other)
	{
	}
}