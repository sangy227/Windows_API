#include "Mon3_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
ya::Mon3_HPbar::Mon3_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon3_HPbar::~Mon3_HPbar()
{
}

void ya::Mon3_HPbar::OnInit()
{
}

void ya::Mon3_HPbar::OnActive()
{
}

void ya::Mon3_HPbar::OnInActive()
{
}

void ya::Mon3_HPbar::OnTick()
{
}

void ya::Mon3_HPbar::OnRender(HDC hdc)
{
	

	if (mImage == nullptr)
		return;

	/*if (mTarget == nullptr)
		return;*/

	chicken* mchicken = dynamic_cast<chicken*>(mTarget);
	//int hp = mchicken->GetHp();
	float xRatio = (/*hp*/100 / 100.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon3_HPbar::OnClear()
{
}
