#include "TitleSelectPlayer3.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaImage.h"
namespace ya {
	TitleSelectPlayer3::TitleSelectPlayer3()
	{
		SetPos({ 935.0f, 675.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImages[0] == nullptr)
		{
			mImages[0] = Resources::Load<Image>(L"mc_idle-1", L"..\\Resources\\Image\\Object\\TitleSelectPlayer\\mc_idle-1.bmp");
		}

		mAnimator = new AniMator(AniMator::Mode::UIGameObject);

		mAnimator->CreateAnimation(L"TitleSelectPlayer3", mImages[0]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.3f);

		mAnimator->Play(L"TitleSelectPlayer3", true);

		AddComponent(mAnimator);
	}
	TitleSelectPlayer3::~TitleSelectPlayer3()
	{
	}
	void TitleSelectPlayer3::Tick()
	{
		GameObject::Tick();
	}
	void TitleSelectPlayer3::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}