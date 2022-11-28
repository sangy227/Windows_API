#include "TitleSelectPlayer6.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaImage.h"
namespace ya {
	TitleSelectPlayer6::TitleSelectPlayer6()
	{
		SetPos({ 925.0f, 675.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImages[0] == nullptr)
		{
			mImages[0] = Resources::Load<Image>(L"tote idle2", L"..\\Resources\\Image\\Object\\TitleSelectPlayer\\tote idle2.bmp");
		}

		mAnimator = new AniMator(AniMator::Mode::UIGameObject);

		mAnimator->CreateAnimation(L"TitleSelectPlayer6", mImages[0]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.3f);

		mAnimator->Play(L"TitleSelectPlayer6", true);

		AddComponent(mAnimator);
	}
	TitleSelectPlayer6::~TitleSelectPlayer6()
	{
	}
	void TitleSelectPlayer6::Tick()
	{
		GameObject::Tick();
	}
	void TitleSelectPlayer6::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}