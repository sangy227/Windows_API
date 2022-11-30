#include "Inventory.h"
#include "yaImage.h"
#include "yaInput.h"

namespace ya {
	Inventory::Inventory(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&Inventory::Click, this);
	}
	Inventory::~Inventory()
	{
	}
	void Inventory::OnInit()
	{
	}
	void Inventory::OnActive()
	{
	}
	void Inventory::OnInActive()
	{
	}
	void Inventory::OnTick()
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
	void Inventory::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f ,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void Inventory::OnClear()
	{
	}
	void Inventory::Click()
	{
	}
}