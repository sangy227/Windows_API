#include "TitleSelectBg8.h"
#include "yaImage.h"
#include "yaInput.h"

namespace ya {
	TitleSelectBg8::TitleSelectBg8(eUIType type)
		:UIBase(type)
	{
	}
	TitleSelectBg8::~TitleSelectBg8()
	{
	}
	void TitleSelectBg8::OnInit()
	{
	}
	void TitleSelectBg8::OnActive()
	{
	}
	void TitleSelectBg8::OnInActive()
	{
	}
	void TitleSelectBg8::OnTick()
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
	void TitleSelectBg8::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth(), mImage->GetHeight(),
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void TitleSelectBg8::OnClear()
	{
	}
	void TitleSelectBg8::Click()
	{
	}
}