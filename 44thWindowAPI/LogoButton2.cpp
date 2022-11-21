#include "LogoButton2.h"
#include "yaImage.h"
#include "yaInput.h"

ya::LogoButton2::LogoButton2(eUIType type)
	:UIBase(type)
	{
		mOnClick = std::bind(&LogoButton2::Click, this);
}

ya::LogoButton2::~LogoButton2()
{
}

void ya::LogoButton2::OnInit()
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

void ya::LogoButton2::OnActive()
{
}

void ya::LogoButton2::OnInActive()
{
}

void ya::LogoButton2::OnTick()
{
}

void ya::LogoButton2::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::LogoButton2::OnClear()
{
}

void ya::LogoButton2::Click()
{
}
