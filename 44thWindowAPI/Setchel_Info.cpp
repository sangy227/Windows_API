#include "Setchel_Info.h"
#include "yaImage.h"

namespace ya {
	Setchel_Info::Setchel_Info(eUIType type)
		:UIBase(type)
	{
	}
	Setchel_Info::~Setchel_Info()
	{
	}
	void Setchel_Info::OnInit()
	{
	}
	void Setchel_Info::OnActive()
	{
	}
	void Setchel_Info::OnInActive()
	{
	}
	void Setchel_Info::OnTick()
	{
	}
	void Setchel_Info::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth(), mImage->GetHeight() ,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));
	}
	void Setchel_Info::OnClear()
	{
	}
}