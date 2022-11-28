#include "TitleSelectPlayer8.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaImage.h"

namespace ya {
	TitleSelectPlayer8::TitleSelectPlayer8()
	{
		SetPos({ 825.0f, 675.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImages[0] == nullptr)
		{
			mImages[0] = Resources::Load<Image>(L"SatchelIdle", L"..\\Resources\\Image\\Object\\TitleSelectPlayer\\SatchelIdle.bmp");
		}

		mAnimator = new AniMator(AniMator::Mode::UIGameObject);

		mAnimator->CreateAnimation(L"TitleSelectPlayer8", mImages[0]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.3f);

		mAnimator->Play(L"TitleSelectPlayer8", true);

		AddComponent(mAnimator);
	}
	TitleSelectPlayer8::~TitleSelectPlayer8()
	{
	}
	void TitleSelectPlayer8::Tick()
	{
		GameObject::Tick();
	}
	void TitleSelectPlayer8::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}