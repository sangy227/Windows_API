#include "Mon10_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
ya::Mon10_HPbar::Mon10_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon10_HPbar::~Mon10_HPbar()
{
}

void ya::Mon10_HPbar::OnInit()
{
}

void ya::Mon10_HPbar::OnActive()
{
}

void ya::Mon10_HPbar::OnInActive()
{
}

void ya::Mon10_HPbar::OnTick()
{
}

void ya::Mon10_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	/*if (mTarget == nullptr)
		return;*/

	bandit_lord* mbandit_lord = dynamic_cast<bandit_lord*>(mTarget);
	//int hp = mchicken->GetHp();
	float xRatio = (/*hp*/100 / 100.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon10_HPbar::OnClear()
{
}
