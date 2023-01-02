#include "Mon9_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
ya::Mon9_HPbar::Mon9_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon9_HPbar::~Mon9_HPbar()
{
}

void ya::Mon9_HPbar::OnInit()
{
}

void ya::Mon9_HPbar::OnActive()
{
}

void ya::Mon9_HPbar::OnInActive()
{
}

void ya::Mon9_HPbar::OnTick()
{
}

void ya::Mon9_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	/*if (mTarget == nullptr)
		return;*/

	cultist* mcultist = dynamic_cast<cultist*>(mTarget);
	//int hp = mchicken->GetHp();
	float xRatio = (/*hp*/100 / 100.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon9_HPbar::OnClear()
{
}
