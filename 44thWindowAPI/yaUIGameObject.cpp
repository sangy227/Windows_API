#include "yaUIGameObject.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaImage.h"

ya::UIGameObject::UIGameObject()
{

	SetPos({ 535.0f, 675.0f });
	SetScale({ 3.0f, 3.0f });

	if (mImages[0] == nullptr)
	{
		mImages[0] = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Player1.bmp");
	}

	mAnimator = new AniMator(AniMator::Mode::UIGameObject);

	mAnimator->CreateAnimation(L"Idle", mImages[0]
		, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
		, Vector2(-24.0f, -48.0f), 4, 0.2f);

	mAnimator->Play(L"Idle", true);
	
	AddComponent(mAnimator);
}

ya::UIGameObject::~UIGameObject()
{
}

void ya::UIGameObject::Tick()
{
	GameObject::Tick();
}

void ya::UIGameObject::Render(HDC hdc)
{
	GameObject::Render(hdc);
}
