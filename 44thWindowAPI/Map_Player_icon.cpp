#include "Map_Player_icon.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaTime.h"

ya::Map_Player_icon::Map_Player_icon(eUIType type)
	:UIBase(type)
	, zero100(0)
{
	mOnClick = std::bind(&Map_Player_icon::Click, this);
}

ya::Map_Player_icon::~Map_Player_icon()
{
}

void ya::Map_Player_icon::OnInit()
{
}

void ya::Map_Player_icon::OnActive()
{
}

void ya::Map_Player_icon::OnInActive()
{
}

void ya::Map_Player_icon::OnTick()
{
	Vector2 mousePos = Input::GetMousePos();
	Vector2 size = GetSize();
	
	UINT speed = 200;
	

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

	if (KEY_DOWN(eKeyCode::S))
	{
		mIconState = Player_Icon_Move::DEFALUT;
	}
	
	//mIconState = Player_Icon_Move::DOWN;
	
	switch (mIconState)
	{
		case ya::UIBase::Player_Icon_Move::DOWN:
		{
			Vector2 pos = GetPos();
			pos.y += speed * Time::DeltaTime();
			SetPos(pos);
		}
			break;
		case ya::UIBase::Player_Icon_Move::UP:
		{
			Vector2 pos = GetPos();
			pos.y -= speed * Time::DeltaTime();
			SetPos(pos);
		}
			break;
		case ya::UIBase::Player_Icon_Move::LEFT:
		{
			Vector2 pos = GetPos();
			pos.x -= speed * Time::DeltaTime();
			SetPos(pos);
		}
			break;
		case ya::UIBase::Player_Icon_Move::RIGHT:
		{
			Vector2 pos = GetPos();
			pos.x += speed * Time::DeltaTime();
			SetPos(pos);
		}
		break;
		default:
			break;
	}
}

void ya::Map_Player_icon::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 5.0f, mImage->GetHeight() * 5.0f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Map_Player_icon::OnClear()
{
}

void ya::Map_Player_icon::Click()
{
	
}
