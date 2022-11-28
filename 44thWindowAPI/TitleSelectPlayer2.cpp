#include "TitleSelectPlayer2.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaImage.h"
namespace ya {
	TitleSelectPlayer2::TitleSelectPlayer2()
	{
		SetPos({ 735.0f, 675.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImages[0] == nullptr)
		{
			mImages[0] = Resources::Load<Image>(L"mc_idle_red", L"..\\Resources\\Image\\Object\\TitleSelectPlayer\\mc_idle_red.bmp");
		}

		mAnimator = new AniMator(AniMator::Mode::UIGameObject);

		mAnimator->CreateAnimation(L"TitleSelectPlayer2", mImages[0]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.3f);

		mAnimator->Play(L"TitleSelectPlayer2", true);

		AddComponent(mAnimator);
	}
	TitleSelectPlayer2::~TitleSelectPlayer2()
	{
	}
	void TitleSelectPlayer2::Tick()
	{
		GameObject::Tick();
	}
	void TitleSelectPlayer2::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}