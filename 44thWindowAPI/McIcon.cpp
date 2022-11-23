#include "McIcon.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaUIManager.h"

namespace ya {
	McIcon::McIcon(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&McIcon::Click, this);
	}
	McIcon::~McIcon()
	{
	}
	void McIcon::OnInit()
	{
	}
	void McIcon::OnActive()
	{
	}
	void McIcon::OnInActive()
	{
	}
	void McIcon::OnTick()
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
	void McIcon::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void McIcon::OnClear()
	{
	}
	void McIcon::Click()
	{
		UIManager::Pop(eUIType::Tote_Info);
		UIManager::Pop(eUIType::Cr8_Info);
		UIManager::Pop(eUIType::Setchel_Info);

		//UIManager::Push(eUIType::TitleDefault);
		UIManager::Push(eUIType::Mc_Info);
	}
}