#include "TitleSelectBg4.h"
#include "yaImage.h"
#include "yaInput.h"

namespace ya {
	TitleSelectBg4::TitleSelectBg4(eUIType type)
		:UIBase(type)
	{
	}
	TitleSelectBg4::~TitleSelectBg4()
	{
	}
	void TitleSelectBg4::OnInit()
	{
	}
	void TitleSelectBg4::OnActive()
	{
	}
	void TitleSelectBg4::OnInActive()
	{
	}
	void TitleSelectBg4::OnTick()
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
	void TitleSelectBg4::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth(), mImage->GetHeight(),
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void TitleSelectBg4::OnClear()
	{
	}
	void TitleSelectBg4::Click()
	{
	}
}