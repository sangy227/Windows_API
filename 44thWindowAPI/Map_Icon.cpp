#include "Map_Icon.h"
#include "yaInput.h"
#include "yaImage.h"

namespace ya {
	Map_Icon::Map_Icon(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&Map_Icon::Click, this);
	}
	Map_Icon::~Map_Icon()
	{
	}
	void Map_Icon::OnInit()
	{
	}
	void Map_Icon::OnActive()
	{
	}
	void Map_Icon::OnInActive()
	{
	}
	void Map_Icon::OnTick()
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
	void Map_Icon::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth(), mImage->GetHeight(),
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void Map_Icon::OnClear()
	{
	}
	void Map_Icon::Click()
	{
	}
}