#include "LogoButton5.h"
#include "yaInput.h"
#include "yaImage.h"

namespace ya {
	LogoButton5::LogoButton5(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&LogoButton5::Click, this);
	}
	LogoButton5::~LogoButton5()
	{
	}
	void LogoButton5::OnInit()
	{
	}
	void LogoButton5::OnActive()
	{
	}
	void LogoButton5::OnInActive()
	{
	}
	void LogoButton5::OnTick()
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
	void LogoButton5::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void LogoButton5::OnClear()
	{
	}
	void LogoButton5::Click()
	{
	}
}