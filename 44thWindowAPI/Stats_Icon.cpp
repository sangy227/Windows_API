#include "Stats_Icon.h"
#include "yaInput.h"
#include "yaImage.h"

namespace ya {
	Stats_Icon::Stats_Icon(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&Stats_Icon::Click, this);
	}
	Stats_Icon::~Stats_Icon()
	{
	}
	void Stats_Icon::OnInit()
	{
	}
	void Stats_Icon::OnActive()
	{
	}
	void Stats_Icon::OnInActive()
	{
	}
	void Stats_Icon::OnTick()
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
	void Stats_Icon::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() , mImage->GetHeight() ,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void Stats_Icon::OnClear()
	{
	}
	void Stats_Icon::Click()
	{
	}
}