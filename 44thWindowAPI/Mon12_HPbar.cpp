#include "Mon12_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
ya::Mon12_HPbar::Mon12_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon12_HPbar::~Mon12_HPbar()
{
}

void ya::Mon12_HPbar::OnInit()
{
}

void ya::Mon12_HPbar::OnActive()
{
}

void ya::Mon12_HPbar::OnInActive()
{
}

void ya::Mon12_HPbar::OnTick()
{
}

void ya::Mon12_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	/*if (mTarget == nullptr)
		return;*/

	Hare_Defender* mHare_Defender = dynamic_cast<Hare_Defender*>(mTarget);
	//int hp = mchicken->GetHp();
	float xRatio = (/*hp*/100 / 100.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon12_HPbar::OnClear()
{
}
