#include "TitleSelectButton2.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaUIManager.h"

namespace ya {
	TitleSelectButton2::TitleSelectButton2(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&TitleSelectButton2::Click, this);
	}
	TitleSelectButton2::~TitleSelectButton2()
	{
	}
	void TitleSelectButton2::OnInit()
	{
	}
	void TitleSelectButton2::OnActive()
	{
	}
	void TitleSelectButton2::OnInActive()
	{
	}
	void TitleSelectButton2::OnTick()
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
	void TitleSelectButton2::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void TitleSelectButton2::OnClear()
	{
	}
	void TitleSelectButton2::Click()
	{
		UIManager::Pop(eUIType::Mc_Info);
		UIManager::Pop(eUIType::Tote_Info);
		UIManager::Pop(eUIType::Cr8_Info);
		UIManager::Pop(eUIType::Setchel_Info);

		UIManager::Pop(eUIType::TitleDefault);

		UIManager::Push(eUIType::LogoButton1);
		UIManager::Push(eUIType::LogoButton2);
		UIManager::Push(eUIType::LogoButton3);
		UIManager::Push(eUIType::LogoButton4);
		UIManager::Push(eUIType::LogoButton5);
		UIManager::Push(eUIType::LogoButton6);
	}
}