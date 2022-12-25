#include "Enemie_icon02.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
ya::Enemie_icon02::Enemie_icon02(eUIType type)
	:UIBase(type)
{
	mOnClick = std::bind(&Enemie_icon02::Click, this);
}

ya::Enemie_icon02::~Enemie_icon02()
{
}

void ya::Enemie_icon02::OnInit()
{
}

void ya::Enemie_icon02::OnActive()
{
}

void ya::Enemie_icon02::OnInActive()
{
}

void ya::Enemie_icon02::OnTick()
{
	Vector2 mousePos = Input::GetMousePos();
	Vector2 size = GetSize();

	if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x * 5.0f
		&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y * 5.0f)
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

void ya::Enemie_icon02::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 5.0f, mImage->GetHeight() * 5.0f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Enemie_icon02::OnClear()
{
}

void ya::Enemie_icon02::Click()
{
	mIconState = Player_Icon_Move::LEFT;

}