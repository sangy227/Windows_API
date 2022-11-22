#include "LogoButton6.h"
#include "yaInput.h"
#include "yaImage.h"

namespace ya {
	LogoButton6::LogoButton6(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&LogoButton6::Click, this);
	}
	LogoButton6::~LogoButton6()
	{
	}
	void LogoButton6::OnInit()
	{
	}
	void LogoButton6::OnActive()
	{
	}
	void LogoButton6::OnInActive()
	{
	}
	void LogoButton6::OnTick()
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
	void LogoButton6::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void LogoButton6::OnClear()
	{
	}
	void LogoButton6::Click()
	{

	}
}