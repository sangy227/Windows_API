#include "LogoButton3.h"
#include "yaImage.h"
#include "yaInput.h"


namespace ya {
	LogoButton3::LogoButton3(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&LogoButton3::Click, this);
	}
	LogoButton3::~LogoButton3()
	{
	}
	void LogoButton3::OnInit()
	{
	}
	void LogoButton3::OnActive()
	{
	}
	void LogoButton3::OnInActive()
	{
	}
	void LogoButton3::OnTick()
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
	void LogoButton3::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void LogoButton3::OnClear()
	{
	}
	void LogoButton3::Click()
	{
	}
}