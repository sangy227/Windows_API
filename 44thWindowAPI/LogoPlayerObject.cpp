#include "LogoPlayerObject.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaImage.h"

namespace ya {
	LogoPlayerObject::LogoPlayerObject()
	{
		SetName(L"LogoPlayerObject");
		SetPos({ 1170.0f, 670.0f });
		SetScale({ 4.0f, 4.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"LogoPlayerObject", L"..\\Resources\\Image\\tote_win.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Win", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.15f);

		mAnimator->Play(L"Win", true);

		AddComponent(mAnimator);
	}
	LogoPlayerObject::~LogoPlayerObject()
	{
	}
	void LogoPlayerObject::Tick()
	{
		GameObject::Tick();

	}
	void LogoPlayerObject::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}