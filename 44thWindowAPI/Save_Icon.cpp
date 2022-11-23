#include "Save_Icon.h"
#include "yaInput.h"
#include "yaImage.h"

namespace ya {
	Save_Icon::Save_Icon(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&Save_Icon::Click, this);
	}
	Save_Icon::~Save_Icon()
	{
	}
	void Save_Icon::OnInit()
	{
	}
	void Save_Icon::OnActive()
	{
	}
	void Save_Icon::OnInActive()
	{
	}
	void Save_Icon::OnTick()
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
	void Save_Icon::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth(), mImage->GetHeight(),
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void Save_Icon::OnClear()
	{
	}
	void Save_Icon::Click()
	{
	}
}