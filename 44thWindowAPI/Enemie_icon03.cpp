#include "Enemie_icon03.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
ya::Enemie_icon03::Enemie_icon03(eUIType type)
	:UIBase(type)
{
	mOnClick = std::bind(&Enemie_icon03::Click, this);
}

ya::Enemie_icon03::~Enemie_icon03()
{
}

void ya::Enemie_icon03::OnInit()
{
}

void ya::Enemie_icon03::OnActive()
{
}

void ya::Enemie_icon03::OnInActive()
{
}

void ya::Enemie_icon03::OnTick()
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

void ya::Enemie_icon03::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 5.0f, mImage->GetHeight() * 5.0f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Enemie_icon03::OnClear()
{
}

void ya::Enemie_icon03::Click()
{
	mIconState = Player_Icon_Move::UP;

}
