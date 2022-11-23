#include "TopLayerDefault.h"
#include "yaImage.h"

namespace ya {
	TopLayerDefault::TopLayerDefault(eUIType type)
		:UIBase(type)
	{
	}
	TopLayerDefault::~TopLayerDefault()
	{
	}
	void TopLayerDefault::OnInit()
	{
	}
	void TopLayerDefault::OnActive()
	{
	}
	void TopLayerDefault::OnInActive()
	{
	}
	void TopLayerDefault::OnTick()
	{
	}
	void TopLayerDefault::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() , mImage->GetHeight() ,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));
	}
	void TopLayerDefault::OnClear()
	{
	}
}