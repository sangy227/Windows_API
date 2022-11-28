#include "TitleSelectPlayer4.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaImage.h"

namespace ya {
	TitleSelectPlayer4::TitleSelectPlayer4()
	{
		SetPos({ 1130.0f, 680.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImages[0] == nullptr)
		{
			mImages[0] = Resources::Load<Image>(L"cthulhu_idle", L"..\\Resources\\Image\\Object\\TitleSelectPlayer\\cthulhu_idle.bmp");
		}

		mAnimator = new AniMator(AniMator::Mode::UIGameObject);

		mAnimator->CreateAnimation(L"TitleSelectPlayer4", mImages[0]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.3f);

		mAnimator->Play(L"TitleSelectPlayer4", true);

		AddComponent(mAnimator);
	}
	TitleSelectPlayer4::~TitleSelectPlayer4()
	{
	}
	void TitleSelectPlayer4::Tick()
	{
		GameObject::Tick();
	}
	void TitleSelectPlayer4::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}