#include "frog_2.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaSound.h"
#include "yaSoundManager.h"
#include "yaScene.h"

namespace ya {
	frog_2::frog_2()
		:mHP(7)
	{
		SetName(L"frog_2");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"frog_2", L"..\\Resources\\Image\\Monster\\frog_2.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	frog_2::frog_2(Vector2 position)
		:mHP(7)
	{
		SetName(L"frog_2");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"frog_2", L"..\\Resources\\Image\\Monster\\frog_2.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);



		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	frog_2::~frog_2()
	{
	}
	void frog_2::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		if (mHP < 0) {
			Sound* mbSound = Scene::mSound[9];
			mbSound->Play(false);
			Death();
			UIManager::Pop(eUIType::heart02);

			UIBase::mMons_target_int++;
			UIBase::Mons_Remaining -= 1;

		}
	}
	void frog_2::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void frog_2::OnCollisionEnter(Collider* other)
	{
	}
	void frog_2::OnCollisionStay(Collider* other)
	{
	}
	void frog_2::OnCollisionExit(Collider* other)
	{
	}
}