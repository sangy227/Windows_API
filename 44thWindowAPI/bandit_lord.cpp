#include "bandit_lord.h"

#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaUIManager.h"
namespace ya {
	bandit_lord::bandit_lord()
		:mHP(5)
	{
		SetName(L"bandit_lord");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"bandit_lord", L"..\\Resources\\Image\\Monster\\bandit lord.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	bandit_lord::bandit_lord(Vector2 position)
		:mHP(5)
	{
		SetName(L"bandit_lord");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"bandit_lord", L"..\\Resources\\Image\\Monster\\bandit lord.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	bandit_lord::~bandit_lord()
	{
	}
	void bandit_lord::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		if (mHP < 0) {
			Death();
			UIManager::Pop(eUIType::heart02);

			UIBase::mMons_target_int++;
			UIBase::Mons_Remaining -= 1;

		}
	}
	void bandit_lord::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void bandit_lord::OnCollisionEnter(Collider* other)
	{
	}
	void bandit_lord::OnCollisionStay(Collider* other)
	{
	}
	void bandit_lord::OnCollisionExit(Collider* other)
	{
	}
}