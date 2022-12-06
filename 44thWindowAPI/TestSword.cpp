#include "TestSword.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaUIManager.h"

namespace ya {
	TestSword::TestSword(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&TestSword::Click, this);
	}
	TestSword::~TestSword()
	{
	}
	void TestSword::OnInit()
	{
	}
	void TestSword::OnActive()
	{
	}
	void TestSword::OnInActive()
	{
	}
	void TestSword::OnTick()
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
	void TestSword::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 4.0f, mImage->GetHeight() * 4.0f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void TestSword::OnClear()
	{
	}
	void TestSword::Click()
	{
	}
}