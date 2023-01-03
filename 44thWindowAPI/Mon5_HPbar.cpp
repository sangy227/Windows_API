#include "Mon5_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
ya::Mon5_HPbar::Mon5_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon5_HPbar::~Mon5_HPbar()
{
}

void ya::Mon5_HPbar::OnInit()
{
}

void ya::Mon5_HPbar::OnActive()
{
}

void ya::Mon5_HPbar::OnInActive()
{
}

void ya::Mon5_HPbar::OnTick()
{
}

void ya::Mon5_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	if (mTarget == nullptr)
		return;

	cultist_blade* mcultist_blade = dynamic_cast<cultist_blade*>(mTarget);
	int hp = mcultist_blade->GetHp();
	float xRatio = (hp / 5.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon5_HPbar::OnClear()
{
}
