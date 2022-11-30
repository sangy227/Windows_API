#include "Map_bg.h"
#include "yaImage.h"
#include "yaInput.h"

namespace ya {
	Map_bg::Map_bg(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&Map_bg::Click, this);
	}
	Map_bg::~Map_bg()
	{
	}
	void Map_bg::OnInit()
	{
	}
	void Map_bg::OnActive()
	{
	}
	void Map_bg::OnInActive()
	{
	}
	void Map_bg::OnTick()
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
	void Map_bg::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 7.0f, mImage->GetHeight() * 4.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void Map_bg::OnClear()
	{
	}
	void Map_bg::Click()
	{
	}
}