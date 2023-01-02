#include "Mon14_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
ya::Mon14_HPbar::Mon14_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon14_HPbar::~Mon14_HPbar()
{
}

void ya::Mon14_HPbar::OnInit()
{
}

void ya::Mon14_HPbar::OnActive()
{
}

void ya::Mon14_HPbar::OnInActive()
{
}

void ya::Mon14_HPbar::OnTick()
{
}

void ya::Mon14_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	/*if (mTarget == nullptr)
		return;*/

	fire_cobra* mfire_cobra = dynamic_cast<fire_cobra*>(mTarget);
	//int hp = mchicken->GetHp();
	float xRatio = (/*hp*/100 / 100.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon14_HPbar::OnClear()
{
}
