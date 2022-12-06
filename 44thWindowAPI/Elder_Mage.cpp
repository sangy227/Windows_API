#include "Elder_Mage.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"
namespace ya {
	Elder_Mage::Elder_Mage()
	{
		SetName(L"Elder_Mage");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Elder_Mage", L"..\\Resources\\Image\\Monster\\Elder_Mage.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	Elder_Mage::Elder_Mage(Vector2 position)
	{
		SetName(L"Elder_Mage");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Elder_Mage", L"..\\Resources\\Image\\Monster\\Elder_Mage.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	Elder_Mage::~Elder_Mage()
	{
	}
	void Elder_Mage::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);
	}
	void Elder_Mage::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Elder_Mage::OnCollisionEnter(Collider* other)
	{
	}
	void Elder_Mage::OnCollisionStay(Collider* other)
	{
	}
	void Elder_Mage::OnCollisionExit(Collider* other)
	{
	}
}