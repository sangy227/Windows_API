#include "TitleSelectPlayer.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaImage.h"

namespace ya {
	TitleSelectPlayer::TitleSelectPlayer()
	{
		SetPos({ 535.0f, 675.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImages[0] == nullptr)
		{
			mImages[0] = Resources::Load<Image>(L"mc_idle", L"..\\Resources\\Image\\Object\\TitleSelectPlayer\\mc_idle.bmp");
		}

		mAnimator = new AniMator(AniMator::Mode::UIGameObject);

		mAnimator->CreateAnimation(L"TitleSelectPlayer", mImages[0]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.3f);

		mAnimator->Play(L"TitleSelectPlayer", true);

		AddComponent(mAnimator);
	}
	TitleSelectPlayer::~TitleSelectPlayer()
	{
	}
	void TitleSelectPlayer::Tick()
	{
		GameObject::Tick();
	}
	void TitleSelectPlayer::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}