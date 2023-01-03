#include "Mon11_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
ya::Mon11_HPbar::Mon11_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon11_HPbar::~Mon11_HPbar()
{
}

void ya::Mon11_HPbar::OnInit()
{
}

void ya::Mon11_HPbar::OnActive()
{
}

void ya::Mon11_HPbar::OnInActive()
{
}

void ya::Mon11_HPbar::OnTick()
{
}

void ya::Mon11_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;


	if (mTarget == nullptr)
		return;

	legman* mlegman = dynamic_cast<legman*>(mTarget);
	int hp = mlegman->GetHp();
	float xRatio = (hp / 5.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon11_HPbar::OnClear()
{
}
