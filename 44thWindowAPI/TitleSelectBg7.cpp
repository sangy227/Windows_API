#include "TitleSelectBg7.h"
#include "yaImage.h"
#include "yaInput.h"

namespace ya {
	TitleSelectBg7::TitleSelectBg7(eUIType type)
		:UIBase(type)
	{
	}
	TitleSelectBg7::~TitleSelectBg7()
	{
	}
	void TitleSelectBg7::OnInit()
	{
	}
	void TitleSelectBg7::OnActive()
	{
	}
	void TitleSelectBg7::OnInActive()
	{
	}
	void TitleSelectBg7::OnTick()
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
	void TitleSelectBg7::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth(), mImage->GetHeight(),
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void TitleSelectBg7::OnClear()
	{
	}
	void TitleSelectBg7::Click()
	{
	}
}