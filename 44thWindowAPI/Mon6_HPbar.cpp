#include "Mon6_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
ya::Mon6_HPbar::Mon6_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon6_HPbar::~Mon6_HPbar()
{
}

void ya::Mon6_HPbar::OnInit()
{
}

void ya::Mon6_HPbar::OnActive()
{
}

void ya::Mon6_HPbar::OnInActive()
{
}

void ya::Mon6_HPbar::OnTick()
{
}

void ya::Mon6_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	if (mTarget == nullptr)
		return;

	hawk_knight* mhawk_knight = dynamic_cast<hawk_knight*>(mTarget);
	int hp = mhawk_knight->GetHp();
	float xRatio = (hp / 5.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon6_HPbar::OnClear()
{
}
