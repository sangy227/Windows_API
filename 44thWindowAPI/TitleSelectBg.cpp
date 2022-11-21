#include "TitleSelectBg.h"
#include "yaImage.h"
#include "yaInput.h"

namespace ya {
	TitleSelectBg::TitleSelectBg(eUIType type)
		:UIBase(type)
	{
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
	}
	void TitleSelectBg::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth()  , mImage->GetHeight() ,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void TitleSelectBg::OnClear()
	{
	}
	void TitleSelectBg::Click()
	{
	}
}