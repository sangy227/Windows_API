#include "TestButton.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaUIManager.h"

namespace ya {
	TestButton::TestButton(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&TestButton::Click, this);
	}
	TestButton::~TestButton()
	{
	}
	void TestButton::OnInit()
	{
	}
	void TestButton::OnActive()
	{
	}
	void TestButton::OnInActive()
	{
	}
	void TestButton::OnTick()
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
	void TestButton::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			/*0.82 , 0.82 ÇØ¾ß ÀÎº¥Åä¸® ºóÄ­°ú µü¸ÂÀ½*/
			mImage->GetWidth() * 0.82f, mImage->GetHeight() * 0.82f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void TestButton::OnClear()
	{
	}
	void TestButton::Click()
	{
		UIManager::Pop(eUIType::TestButton);

	}
}