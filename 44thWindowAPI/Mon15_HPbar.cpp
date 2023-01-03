#include "Mon15_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
ya::Mon15_HPbar::Mon15_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon15_HPbar::~Mon15_HPbar()
{
}

void ya::Mon15_HPbar::OnInit()
{
}

void ya::Mon15_HPbar::OnActive()
{
}

void ya::Mon15_HPbar::OnInActive()
{
}

void ya::Mon15_HPbar::OnTick()
{
}

void ya::Mon15_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	if (mTarget == nullptr)
		return;

	head_honcho* mhead_honcho = dynamic_cast<head_honcho*>(mTarget);
	int hp = mhead_honcho->GetHp();
	float xRatio = (hp / 5.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon15_HPbar::OnClear()
{
}
