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

		for (UIBase* child : mChilds)
		{
			child->OnInit();
		}
	}
	void UIBase::Active()
	{
		mbEnable = true;
		OnActive();

		for (UIBase* child : mChilds)
		{
			child->mbEnable = true;
			child->OnActive();
		}
	}
	void UIBase::InActive()
	{
		

		for (UIBase* child : mChilds)
		{
			child->OnInActive();
			child->mbEnable = false;
		}
		OnInActive();
		mbEnable = false;
	}
	void UIBase::Tick()
	{
		if (mbEnable == false)
			return;

		OnTick();

		if (mParent)
			mScreenPos = mParent->GetPos() + mPos;
		else
			mScreenPos = mPos;

		for (UIBase* child : mChilds)
		{
			if (child->mbEnable)
			{
				child->Tick();
			}
		}
	}
	void UIBase::Render(HDC hdc)
	{
		if (mbEnable == false)
			return;
	
		OnRender(hdc);

		for (UIBase* child : mChilds)
		{
			if (child->mbEnable)
			{
				child->OnRender(hdc);
			}
		}
	}
	void UIBase::UIClear()
	{
		for (UIBase* child : mChilds)
		{
			//if (child->mbEnable)
			child->OnClear();
		}
		OnClear();
	}
	void UIBase::ImageLoad(const std::wstring& key,const std::wstring& path)
	{
		mImage = Resources::Load<Image>(key, path);

		SetSize(Vector2(mImage->GetWidth(), mImage->GetHeight()));
	}
	void UIBase::AddChild(UIBase* uiBase)
	{
		mChilds.push_back(uiBase);
		uiBase->mParent = this;
	}
}