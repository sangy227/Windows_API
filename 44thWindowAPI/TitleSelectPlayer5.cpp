#include "TitleSelectPlayer5.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaImage.h"

namespace ya {
	TitleSelectPlayer5::TitleSelectPlayer5()
	{
		SetPos({ 725.0f, 675.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImages[0] == nullptr)
		{
			mImages[0] = Resources::Load<Image>(L"Tote Idle", L"..\\Resources\\Image\\Object\\TitleSelectPlayer\\Tote Idle.bmp");
		}

		mAnimator = new AniMator(AniMator::Mode::UIGameObject);

		mAnimator->CreateAnimation(L"TitleSelectPlayer5", mImages[0]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.3f);

		mAnimator->Play(L"TitleSelectPlayer5", true);

		AddComponent(mAnimator);
	}
	TitleSelectPlayer5::~TitleSelectPlayer5()
	{
	}
	void TitleSelectPlayer5::Tick()
	{
		GameObject::Tick();
	}
	void TitleSelectPlayer5::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}