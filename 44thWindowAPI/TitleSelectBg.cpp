#include "TitleSelectBg.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaAniMator.h"
#include "yaResources.h"
#include "yaAnimation.h"

namespace ya {
	TitleSelectBg::TitleSelectBg(eUIType type)
		:UIBase(type)
	{
		mImage2 = Resources::Load<Image>(L"Icon", L"..\\Resources\\Image\\Player1.bmp");

		/*mAniMator = new AniMator();

		mAniMator->CreateAnimation(L"Icon", mImage2
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.2f);

		mAniMator->Play(L"Icon", true);*/
	}
	TitleSelectBg::~TitleSelectBg()
	{
	}
	void TitleSelectBg::OnInit()
	{
	
	}
	void TitleSelectBg::OnActive()
	{
		
	}
	void TitleSelectBg::OnInActive()
	{
		
	}
	void TitleSelectBg::OnTick()
	{
		Vector2 mousePos = Input::GetMousePos();
		Vector2 size = GetSize();

		if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x
			&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y)
		{
			mbMouseOn = true;
		}
		else
		{
			mbMouseOn = false;
		}

		if (KEY_DOWN(eKeyCode::LBTN) && mbMouseOn)
		{
			mOnClick();
		}

		//mAniMator->Tick();
		
	}
	void TitleSelectBg::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth()  , mImage->GetHeight() ,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));

		//mAniMator->Render(hdc);
	}
	void TitleSelectBg::OnClear()
	{
	}
	void TitleSelectBg::Click()
	{
	}
}