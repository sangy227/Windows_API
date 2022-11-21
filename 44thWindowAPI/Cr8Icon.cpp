#include "Cr8Icon.h"
#include "yaImage.h"
#include "yaInput.h"

namespace ya {
	Cr8Icon::Cr8Icon(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&Cr8Icon::Click, this);
	}
	Cr8Icon::~Cr8Icon()
	{
	}
	void Cr8Icon::OnInit()
	{
	}
	void Cr8Icon::OnActive()
	{
	}
	void Cr8Icon::OnInActive()
	{
	}
	void Cr8Icon::OnTick()
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
	void Cr8Icon::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void Cr8Icon::OnClear()
	{
	}
	void Cr8Icon::Click()
	{
	}
}