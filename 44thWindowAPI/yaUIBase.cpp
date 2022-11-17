#include "yaUIBase.h"
#include "yaResources.h"
#include "yaImage.h"

namespace ya {
	UIBase::UIBase(eUIType type)
		: mType(type)
		, mbFullScreen(false)
		, mbEnable(false)
		, mParent(nullptr)
		, mPos(Vector2::Zero)
		, mSize(Vector2::Zero)
	{

	}
	UIBase::~UIBase()
	{
	}
	void UIBase::Initialize()
	{
		OnInit();
	}
	void UIBase::Active()
	{
		mbEnable = true;
		OnActive();
	}
	void UIBase::InActive()
	{
		mbEnable = false;
		OninActive();
	}
	void UIBase::Tick()
	{
		if (mbEnable == false)
			return;

		OnTick();
	}
	void UIBase::Render(HDC hdc)
	{
		if (mbEnable == false)
			return;

		OnRender(hdc);
	}
	void UIBase::UIClear()
	{
		OnClear();
	}
	void UIBase::ImageLoad(const std::wstring& key,const std::wstring& path)
	{
		mImage = Resources::Load<Image>(key, path);

		SetSize(Vector2(mImage->GetWidth(), mImage->GetHeight()));
	}
}