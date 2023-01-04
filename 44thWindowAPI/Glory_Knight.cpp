#include "Glory_Knight.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"
#include "yaUIManager.h"
namespace ya {
	Glory_Knight::Glory_Knight()
		:mHP(5)
	{
		SetName(L"Glory_Knight");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Glory_Knight", L"..\\Resources\\Image\\Monster\\Glory_Knight.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}
	Glory_Knight::Glory_Knight(Vector2 position)
		:mHP(5)
	{
		SetName(L"Glory_Knight");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Glory_Knight", L"..\\Resources\\Image\\Monster\\Glory_Knight.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());

		if (mHP < 0) {
			Death();
			UIManager::Pop(eUIType::heart03);
			UIBase::Mons_Remaining -= 3;

		}
	}
	Glory_Knight::~Glory_Knight()
	{
	}
	void Glory_Knight::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		if (mHP < 0) {
			Death();
			UIManager::Pop(eUIType::heart03);
		}
	}
	void Glory_Knight::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
	void Glory_Knight::OnCollisionEnter(Collider* other)
	{
	}
	void Glory_Knight::OnCollisionStay(Collider* other)
	{
	}
	void Glory_Knight::OnCollisionExit(Collider* other)
	{
	}
}