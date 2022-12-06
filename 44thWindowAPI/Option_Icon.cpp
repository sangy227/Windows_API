#include "Option_Icon.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaSceneManager.h"
#include "yaUIManager.h"

namespace ya {
	Option_Icon::Option_Icon(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&Option_Icon::Click, this);
	}
	Option_Icon::~Option_Icon()
	{
	}
	void Option_Icon::OnInit()
	{
	}
	void Option_Icon::OnActive()
	{
	}
	void Option_Icon::OnInActive()
	{
	}
	void Option_Icon::OnTick()
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
	void Option_Icon::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth(), mImage->GetHeight(),
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void Option_Icon::OnClear()
	{
	}
	void Option_Icon::Click()
	{
		UIManager::Pop(eUIType::TopLayerDefault);
		UIManager::Pop(eUIType::Map_Icon);
		UIManager::Pop(eUIType::Back_Icon);
		UIManager::Pop(eUIType::Map_bg);
		UIManager::Pop(eUIType::Inventory2);


		UIManager::Push(eUIType::LogoButton1);
		UIManager::Push(eUIType::LogoButton2);
		UIManager::Push(eUIType::LogoButton3);
		UIManager::Push(eUIType::LogoButton4);
		UIManager::Push(eUIType::LogoButton5);
		UIManager::Push(eUIType::LogoButton6);

		SceneManager::ChangeScene(eSceneType::Logo);
	}
}