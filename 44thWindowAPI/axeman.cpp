#include "axeman.h"

#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

ya::axeman::axeman()
{
	SetName(L"axeman");
	SetPos({ 1070.0f, 770.0f });
	SetScale({ 3.0f, 3.0f });

	if (mImage == nullptr)
	{
		mImage = Resources::Load<Image>(L"axeman", L"..\\Resources\\Image\\Monster\\axeman.bmp");
	}

	mAnimator = new AniMator();
	mAnimator->CreateAnimation(L"Idle", mImage
		, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
		, Vector2(-24.0f, -48.0f), 4, 0.4f);

	mAnimator->Play(L"Idle", true);

	AddComponent(mAnimator);
	AddComponent(new Collider());
}

ya::axeman::axeman(Vector2 position)
{
	SetName(L"axeman");
	SetPos(position);
	SetScale({ 3.0f, 3.0f });

	if (mImage == nullptr)
	{
		mImage = Resources::Load<Image>(L"axeman", L"..\\Resources\\Image\\Monster\\axeman.bmp");
	}

	mAnimator = new AniMator();
	mAnimator->CreateAnimation(L"Idle", mImage
		, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
		, Vector2(-24.0f, -48.0f), 4, 0.4f);

	mAnimator->Play(L"Idle", true);

	AddComponent(mAnimator);
	AddComponent(new Collider());
}

ya::axeman::~axeman()
{
}

void ya::axeman::Tick()
{
	GameObject::Tick();

	Vector2 pos = GetPos();

	SetPos(pos);
}

void ya::axeman::Render(HDC hdc)
{
	GameObject::Render(hdc);
}

void ya::axeman::OnCollisionEnter(Collider* other)
{
}

void ya::axeman::OnCollisionStay(Collider* other)
{
}

void ya::axeman::OnCollisionExit(Collider* other)
{
}
