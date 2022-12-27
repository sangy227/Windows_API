#include "yaHUD.h"
#include "yaImage.h"
#include "yaPlayer.h"
#include "yaAniMator.h"
#include "yaResources.h"

namespace ya {
	HUD::HUD(eUIType type)
		:UIBase(type)
	{
		/*mAniMator = new AniMator();

		mImage2 = Resources::Load<Image>(L"Icon", L"..\\Resources\\Image\\Player1.bmp");


		mAniMator->CreateAnimation(L"Icon", mImage2
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.2f);

		mAniMator->Play(L"Icon", true);
		mAniMator->SetOwnder(mRectObject);*/
	}
	HUD::~HUD()
	{
	}
	void HUD::OnInit()
	{
	}
	void HUD::OnActive()
	{
	}
	void HUD::OnInActive()
	{
	}
	void HUD::OnTick()
	{
	}
	void HUD::OnRender(HDC hdc)
	{
		if (mImage == nullptr)
			return;

		if (mTarget == nullptr)
			return;

		Player* playerObj = dynamic_cast<Player*>(mTarget);
		int hp = playerObj->GetHp();
		float xRatio = (hp / 100.0f);

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255;

		AlphaBlend(hdc, (int)mScreenPos.x, (int)mScreenPos.y
			, mImage->GetWidth() * xRatio, mImage->GetHeight()
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), func);
	}
	void HUD::OnClear()
	{
	}
}