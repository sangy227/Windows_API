#include "fire_cobra.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaUIManager.h"
namespace ya {
	fire_cobra::fire_cobra()
		:mHP(5)
	{
		SetName(L"fire_cobra");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"fire_cobra", L"..\\Resources\\Image\\Monster\\fire_cobra.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	fire_cobra::fire_cobra(Vector2 position)
		:mHP(5)
	{
		SetName(L"fire_cobra");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"fire_cobra", L"..\\Resources\\Image\\Monster\\fire_cobra.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	fire_cobra::~fire_cobra()
	{
	}
	void fire_cobra::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		if (mHP < 0) {
			Death();
			UIManager::Pop(eUIType::heart03);

			UIBase::mMons_target_int++;

		}
	}
	void fire_cobra::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void fire_cobra::OnCollisionEnter(Collider* other)
	{
	}
	void fire_cobra::OnCollisionStay(Collider* other)
	{
	}
	void fire_cobra::OnCollisionExit(Collider* other)
	{
	}
}