#include "ToteIcon.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaUIManager.h"

namespace ya {
	ToteIcon::ToteIcon(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&ToteIcon::Click, this);
	}
	ToteIcon::~ToteIcon()
	{
	}
	void ToteIcon::OnInit()
	{
	}
	void ToteIcon::OnActive()
	{
	}
	void ToteIcon::OnInActive()
	{
	}
	void ToteIcon::OnTick()
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
	void ToteIcon::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void ToteIcon::OnClear()
	{
	}
	void ToteIcon::Click()
	{

		UIManager::Pop(eUIType::Mc_Info);
		UIManager::Pop(eUIType::Cr8_Info);
		UIManager::Pop(eUIType::Setchel_Info);

		UIManager::Push(eUIType::Tote_Info);
		//?????
		//UIManager::Pop(eUIType::TitleDefault);


	}
}