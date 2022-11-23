#include "Book_Icon.h"
#include "yaInput.h"
#include "yaImage.h"

namespace ya {
	Book_Icon::Book_Icon(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&Book_Icon::Click, this);
	}
	Book_Icon::~Book_Icon()
	{
	}
	void Book_Icon::OnInit()
	{
	}
	void Book_Icon::OnActive()
	{
	}
	void Book_Icon::OnInActive()
	{
	}
	void Book_Icon::OnTick()
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
	void Book_Icon::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth()*1.3f, mImage->GetHeight() * 1.3f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void Book_Icon::OnClear()
	{
	}
	void Book_Icon::Click()
	{
	}
}