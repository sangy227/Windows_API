#include "Mon7_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
ya::Mon7_HPbar::Mon7_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon7_HPbar::~Mon7_HPbar()
{
}

void ya::Mon7_HPbar::OnInit()
{
}

void ya::Mon7_HPbar::OnActive()
{
}

void ya::Mon7_HPbar::OnInActive()
{
}

void ya::Mon7_HPbar::OnTick()
{
}

void ya::Mon7_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	/*if (mTarget == nullptr)
		return;*/

	frog_2* mfrog_2 = dynamic_cast<frog_2*>(mTarget);
	//int hp = mchicken->GetHp();
	float xRatio = (/*hp*/100 / 100.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon7_HPbar::OnClear()
{
}
