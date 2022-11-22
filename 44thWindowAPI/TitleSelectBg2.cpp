#include "TitleSelectBg2.h"
#include "yaImage.h"
#include "yaInput.h"

ya::TitleSelectBg2::TitleSelectBg2(eUIType type)
	:UIBase(type)
{
}

ya::TitleSelectBg2::~TitleSelectBg2()
{
}

void ya::TitleSelectBg2::OnInit()
{
}

void ya::TitleSelectBg2::OnActive()
{
}

void ya::TitleSelectBg2::OnInActive()
{
}

void ya::TitleSelectBg2::OnTick()
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

void ya::TitleSelectBg2::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth(), mImage->GetHeight(),
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::TitleSelectBg2::OnClear()
{
}

void ya::TitleSelectBg2::Click()
{
}
