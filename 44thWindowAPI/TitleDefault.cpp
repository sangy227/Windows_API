#include "TitleDefault.h"
#include "yaImage.h"


namespace ya {
	TitleDefault::TitleDefault(eUIType type)
		:UIBase(type)
	{
	}
	TitleDefault::~TitleDefault()
	{
	}
	void TitleDefault::OnInit()
	{
	}
	void TitleDefault::OnActive()
	{
	}
	void TitleDefault::OnInActive()
	{
	}
	void TitleDefault::OnTick()
	{
	}
	void TitleDefault::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void TitleDefault::OnClear()
	{
	}
}