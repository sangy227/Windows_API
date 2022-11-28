#include "TitleSelectPlayer7.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaImage.h"

namespace ya {
	TitleSelectPlayer7::TitleSelectPlayer7()
	{
		SetPos({ 825.0f, 675.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImages[0] == nullptr)
		{
			mImages[0] = Resources::Load<Image>(L"CR-8 idle", L"..\\Resources\\Image\\Object\\TitleSelectPlayer\\CR-8 idle.bmp");
		}

		mAnimator = new AniMator(AniMator::Mode::UIGameObject);

		mAnimator->CreateAnimation(L"TitleSelectPlayer7", mImages[0]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.3f);

		mAnimator->Play(L"TitleSelectPlayer7", true);

		AddComponent(mAnimator);
	}
	TitleSelectPlayer7::~TitleSelectPlayer7()
	{
	}
	void TitleSelectPlayer7::Tick()
	{
		GameObject::Tick();
	}
	void TitleSelectPlayer7::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}