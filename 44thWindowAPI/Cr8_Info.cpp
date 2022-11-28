#include "Cr8_Info.h"
#include "yaImage.h"


namespace ya {
	Cr8_Info::Cr8_Info(eUIType type)
		:UIBase(type)
	{
	}
	Cr8_Info::~Cr8_Info()
	{
	}
	void Cr8_Info::OnInit()
	{
	}
	void Cr8_Info::OnActive()
	{
	}
	void Cr8_Info::OnInActive()
	{
	}
	void Cr8_Info::OnTick()
	{
	}
	void Cr8_Info::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() , mImage->GetHeight() ,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));
	}
	void Cr8_Info::OnClear()
	{
	}
}