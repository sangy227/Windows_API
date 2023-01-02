#include "Enter_Button.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaUIManager.h"
#include "Item_include.h"

namespace ya {
	Enter_Button::Enter_Button(eUIType type)
		:UIItem(type)
	{
		mOnClick = std::bind(&Enter_Button::Click, this);
	}
	Enter_Button::~Enter_Button()
	{
	}
	void Enter_Button::OnInit()
	{
	}
	void Enter_Button::OnActive()
	{
	}
	void Enter_Button::OnInActive()
	{
	}
	void Enter_Button::OnTick()
	{
		Vector2 mousePos = Input::GetMousePos();
		Vector2 size = GetSize();

		if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x * 0.7f
			&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y * 0.7f)
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
	void Enter_Button::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.7f, mImage->GetHeight() * 0.7f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void Enter_Button::OnClear()
	{
	}
	void Enter_Button::Click()
	{
		
		//Sword* mSword = UIManager::GetUiInstant<Sword>(eUIType::TestSword);
		//Sword* mSword = 
		//mSword->ReSerch();
	}
	
}