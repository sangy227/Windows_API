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

		if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x * 0.819f
			&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y * 0.819f)
		{
			mbMouseOn = true;
		}
		else
		{
			mbMouseOn = false;
		}

		if (KEY_DOWN(eKeyCode::LBTN) && mbMouseOn && LevelUp_Inventory_Count>0)
		{
			mOnClick();
		}
	}
	void TestButton::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			/*0.82 , 0.82 ÇØ¾ß ÀÎº¥Åä¸® ºóÄ­°ú µü¸ÂÀ½*/
			mImage->GetWidth() * 0.818f, mImage->GetHeight() * 0.818f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));

		HBRUSH oldBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
		HPEN bluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);

		/*Rectangle(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			(int)mScreenPos.x + mImage->GetWidth() * 0.818f
			, (int)mScreenPos.y + mImage->GetHeight() * 0.818f);*/

		SelectObject(hdc, oldPen);
		DeleteObject(bluePen);
		SelectObject(hdc, oldBrush);
	}
	void TestButton::OnClear()
	{
	}
	void TestButton::Click()
	{
		//UIManager::Pop(eUIType::TestButton);
		//ExitChild();
		LevelUp_Inventory_Count -= 1;
		mbEnable = false;
	}
}