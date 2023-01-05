#include "legman.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaSound.h"
#include "yaSoundManager.h"
#include "yaScene.h"

namespace ya {
	legman::legman()
		:mHP(6)
	{
		SetName(L"legman");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"legman", L"..\\Resources\\Image\\Monster\\legman.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	legman::legman(Vector2 position)
		:mHP(6)
	{
		SetName(L"legman");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"legman", L"..\\Resources\\Image\\Monster\\legman.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	legman::~legman()
	{
	}
	void legman::Tick()
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
	void legman::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void legman::OnCollisionEnter(Collider* other)
	{
	}
	void legman::OnCollisionStay(Collider* other)
	{
	}
	void legman::OnCollisionExit(Collider* other)
	{
	}
}