#include "SetchelIcon.h"
#include "yaImage.h"
#include "yaInput.h"

namespace ya {
	SetchelIcon::SetchelIcon(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&SetchelIcon::Click, this);
	}
	SetchelIcon::~SetchelIcon()
	{
	}
	void SetchelIcon::OnInit()
	{
	}
	void SetchelIcon::OnActive()
	{
	}
	void SetchelIcon::OnInActive()
	{
	}
	void SetchelIcon::OnTick()
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
	void SetchelIcon::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void SetchelIcon::OnClear()
	{
	}
	void SetchelIcon::Click()
	{

	}
}