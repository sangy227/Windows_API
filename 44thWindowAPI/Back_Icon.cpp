#include "Back_Icon.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaPlayer.h"
#include "yaScene.h"
#include "yaSound.h"
#include "yaSoundManager.h"
#include "yaScene.h"

namespace ya {
	Back_Icon::Back_Icon(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&Back_Icon::Click, this);
	}
	Back_Icon::~Back_Icon()
	{
	}
	void Back_Icon::OnInit()
	{
	}
	void Back_Icon::OnActive()
	{
	}
	void Back_Icon::OnInActive()
	{
	}
	void Back_Icon::OnTick()
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
	void Back_Icon::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth(), mImage->GetHeight(),
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void Back_Icon::OnClear()
	{
	}
	void Back_Icon::Click()
	{
		Sound* mbSound = Scene::mSound[1];
		mbSound->Play(false);
		UIManager::Pop(eUIType::Map_bg);
		UIManager::Pop(eUIType::Inventory2);
		UIManager::Push(eUIType::Inventory2);

		Player* miniPlayer = Scene::player;
		miniPlayer->Player_Idel();

	}
}