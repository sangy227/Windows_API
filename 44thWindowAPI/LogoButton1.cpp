#include "LogoButton1.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaSceneManager.h"

namespace ya
{
	LogoButton1::LogoButton1(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&LogoButton1::Click, this);
	}
	LogoButton1::~LogoButton1()
	{

	}
	void LogoButton1::OnInit()
	{

	}
	void LogoButton1::OnActive()
	{

	}
	void LogoButton1::OnInActive()
	{

	}
	void LogoButton1::OnTick()
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
	void LogoButton1::OnRender(HDC hdc)
	{
		/*BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255;


		AlphaBlend(hdc, (int)mScreenPos.x, (int)mScreenPos.y
			, mImage->GetWidth()*0.8f, mImage->GetHeight()*0.8f
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), func);*/

		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));

	}
	void LogoButton1::OnClear()
	{

	}
	void LogoButton1::Click()
	{
		SceneManager::ChangeScene(eSceneType::PlayOne);
	}
}