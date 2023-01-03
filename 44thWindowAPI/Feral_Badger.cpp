#include "Feral_Badger.h"

#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

namespace ya {
	Feral_Badger::Feral_Badger()
		:mHP(5)
	{
		SetName(L"Feral_Badger");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Feral_Badger", L"..\\Resources\\Image\\Monster\\Feral_Badger.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	Feral_Badger::Feral_Badger(Vector2 position)
		:mHP(5)
	{
		SetName(L"Feral_Badger");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Feral_Badger", L"..\\Resources\\Image\\Monster\\Feral_Badger.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	Feral_Badger::~Feral_Badger()
	{
	}
	void Feral_Badger::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void Feral_Badger::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Feral_Badger::OnCollisionEnter(Collider* other)
	{
	}
	void Feral_Badger::OnCollisionStay(Collider* other)
	{
	}
	void Feral_Badger::OnCollisionExit(Collider* other)
	{
	}
}