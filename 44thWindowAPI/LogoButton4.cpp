#include "LogoButton4.h"
#include "yaImage.h"
#include "yaInput.h"

namespace ya {
	LogoButton4::LogoButton4(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&LogoButton4::Click, this);
	}
	LogoButton4::~LogoButton4()
	{
	}
	void LogoButton4::OnInit()
	{
	}
	void LogoButton4::OnActive()
	{
	}
	void LogoButton4::OnInActive()
	{
	}
	void LogoButton4::OnTick()
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
	void LogoButton4::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void LogoButton4::OnClear()
	{
	}
	void LogoButton4::Click()
	{
	}
}