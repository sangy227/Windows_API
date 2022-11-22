#include "TitleSelectButton1.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaUIManager.h"

namespace ya {
	TitleSelectButton1::TitleSelectButton1(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&TitleSelectButton1::Click, this);
	}
	TitleSelectButton1::~TitleSelectButton1()
	{
	}
	void TitleSelectButton1::OnInit()
	{
	}
	void TitleSelectButton1::OnActive()
	{
	}
	void TitleSelectButton1::OnInActive()
	{
	}
	void TitleSelectButton1::OnTick()
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
	void TitleSelectButton1::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void TitleSelectButton1::OnClear()
	{
	}
	void TitleSelectButton1::Click()
	{

		UIManager::Pop(eUIType::Mc_Info);
		UIManager::Pop(eUIType::TitleDefault);


		SceneManager::ChangeScene(eSceneType::PlayOne);

	}
}