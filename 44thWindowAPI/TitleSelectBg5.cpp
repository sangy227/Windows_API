#include "TitleSelectBg5.h"
#include "yaImage.h"
#include "yaInput.h"

namespace ya {
	TitleSelectBg5::TitleSelectBg5(eUIType type)
		:UIBase(type)
	{
	}
	TitleSelectBg5::~TitleSelectBg5()
	{
	}
	void TitleSelectBg5::OnInit()
	{
	}
	void TitleSelectBg5::OnActive()
	{
	}
	void TitleSelectBg5::OnInActive()
	{
	}
	void TitleSelectBg5::OnTick()
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
	void TitleSelectBg5::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth(), mImage->GetHeight(),
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void TitleSelectBg5::OnClear()
	{
	}
	void TitleSelectBg5::Click()
	{
	}
}