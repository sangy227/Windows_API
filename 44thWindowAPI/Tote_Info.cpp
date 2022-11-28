#include "Tote_Info.h"
#include "yaImage.h"

namespace ya {
	Tote_Info::Tote_Info(eUIType type)
		:UIBase(type)
	{
	}
	Tote_Info::~Tote_Info()
	{
	}
	void Tote_Info::OnInit()
	{
	}
	void Tote_Info::OnActive()
	{
	}
	void Tote_Info::OnInActive()
	{
	}
	void Tote_Info::OnTick()
	{
	}
	void Tote_Info::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() , mImage->GetHeight() ,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));
	}
	void Tote_Info::OnClear()
	{

	}
}
