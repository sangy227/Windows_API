#include "TitleSelectBg3.h"
#include "yaImage.h"
#include "yaInput.h"

namespace ya {
	TitleSelectBg3::TitleSelectBg3(eUIType type)
		:UIBase(type)
	{
	}
	TitleSelectBg3::~TitleSelectBg3()
	{
	}
	void TitleSelectBg3::OnInit()
	{
	}
	void TitleSelectBg3::OnActive()
	{
	}
	void TitleSelectBg3::OnInActive()
	{
	}
	void TitleSelectBg3::OnTick()
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
	void TitleSelectBg3::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth(), mImage->GetHeight(),
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void TitleSelectBg3::OnClear()
	{
	}
	void TitleSelectBg3::Click()
	{
	}
}