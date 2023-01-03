#include "Mon8_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
ya::Mon8_HPbar::Mon8_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon8_HPbar::~Mon8_HPbar()
{
}

void ya::Mon8_HPbar::OnInit()
{
}

void ya::Mon8_HPbar::OnActive()
{
}

void ya::Mon8_HPbar::OnInActive()
{
}

void ya::Mon8_HPbar::OnTick()
{
}

void ya::Mon8_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	if (mTarget == nullptr)
		return;

	crossbowman* mcrossbowman = dynamic_cast<crossbowman*>(mTarget);
	int hp = mcrossbowman->GetHp();
	float xRatio = (hp / 5.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon8_HPbar::OnClear()
{
}
