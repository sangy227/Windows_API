#include "Hare_Defender.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaUIManager.h"
namespace ya {
	Hare_Defender::Hare_Defender()
		:mHP(5)
	{
		SetName(L"Hare_Defender");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Hare_Defender", L"..\\Resources\\Image\\Monster\\Hare_Defender.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	Hare_Defender::Hare_Defender(Vector2 position)
		:mHP(5)
	{
		SetName(L"Hare_Defender");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Hare_Defender", L"..\\Resources\\Image\\Monster\\Hare_Defender.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	Hare_Defender::~Hare_Defender()
	{
	}
	void Hare_Defender::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		if (mHP < 0) {
			Death();
			UIManager::Pop(eUIType::heart04);

			UIBase::mMons_target_int++;
		}
	}
	void Hare_Defender::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Hare_Defender::OnCollisionEnter(Collider* other)
	{
	}
	void Hare_Defender::OnCollisionStay(Collider* other)
	{
	}
	void Hare_Defender::OnCollisionExit(Collider* other)
	{
	}
}