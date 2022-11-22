#include "TitleSelectBg6.h"
#include "yaImage.h"
#include "yaInput.h"

namespace ya {
	TitleSelectBg6::TitleSelectBg6(eUIType type)
		:UIBase(type)
	{
	}
	TitleSelectBg6::~TitleSelectBg6()
	{
	}
	void TitleSelectBg6::OnInit()
	{
	}
	void TitleSelectBg6::OnActive()
	{
	}
	void TitleSelectBg6::OnInActive()
	{
	}
	void TitleSelectBg6::OnTick()
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
	void TitleSelectBg6::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth(), mImage->GetHeight(),
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void TitleSelectBg6::OnClear()
	{
	}
	void TitleSelectBg6::Click()
	{
	}
}