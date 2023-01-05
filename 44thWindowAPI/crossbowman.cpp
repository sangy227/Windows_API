#include "crossbowman.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaSound.h"
#include "yaSoundManager.h"
#include "yaScene.h"

namespace ya {
	crossbowman::crossbowman()
		:mHP(7)
	{
		SetName(L"crossbowman");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"crossbowman", L"..\\Resources\\Image\\Monster\\crossbowman.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	crossbowman::crossbowman(Vector2 position)
		:mHP(7)
	{
		SetName(L"crossbowman");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"crossbowman", L"..\\Resources\\Image\\Monster\\crossbowman.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	crossbowman::~crossbowman()
	{
	}
	void crossbowman::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		if (mHP < 0) {
			Sound* mbSound = Scene::mSound[9];
			mbSound->Play(false);
			Death();
			UIManager::Pop(eUIType::heart03);

			UIBase::mMons_target_int++;
			UIBase::Mons_Remaining -= 1;

		}
	}
	void crossbowman::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void crossbowman::OnCollisionEnter(Collider* other)
	{
	}
	void crossbowman::OnCollisionStay(Collider* other)
	{
	}
	void crossbowman::OnCollisionExit(Collider* other)
	{
	}
}