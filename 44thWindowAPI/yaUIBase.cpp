#include "yaUIBase.h"
namespace ya {
	UIBase::UIBase(eUIType type)
		: mType(type)
		, mbFullScreen(false)
		, mbEnable(false)
	{

	}
	UIBase::~UIBase()
	{
	}
	void UIBase::Initialize()
	{
	}
	void UIBase::Active()
	{
	}
	void UIBase::InActive()
	{
	}
	void UIBase::Tick()
	{
	}
	void UIBase::Render(HDC hdc)
	{
	}
	void UIBase::UIClear()
	{
	}
}