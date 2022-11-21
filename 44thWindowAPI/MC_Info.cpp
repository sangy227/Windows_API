#include "MC_Info.h"
#include "yaImage.h"

namespace ya {
	MC_Info::MC_Info(eUIType type)
		:UIBase(type)
	{
	}
	MC_Info::~MC_Info()
	{
	}
	void MC_Info::OnInit()
	{
	}
	void MC_Info::OnActive()
	{
	}
	void MC_Info::OnInActive()
	{
	}
	void MC_Info::OnTick()
	{
	}
	void MC_Info::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 0.8f, mImage->GetHeight() * 0.8f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));
	}
	void MC_Info::OnClear()
	{
	}
}