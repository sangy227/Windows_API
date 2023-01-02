#include "Mon13_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
ya::Mon13_HPbar::Mon13_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon13_HPbar::~Mon13_HPbar()
{
}

void ya::Mon13_HPbar::OnInit()
{
}

void ya::Mon13_HPbar::OnActive()
{
}

void ya::Mon13_HPbar::OnInActive()
{
}

void ya::Mon13_HPbar::OnTick()
{
}

void ya::Mon13_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	/*if (mTarget == nullptr)
		return;*/

	Feral_Badger* mFeral_Badger = dynamic_cast<Feral_Badger*>(mTarget);
	//int hp = mchicken->GetHp();
	float xRatio = (/*hp*/100 / 100.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon13_HPbar::OnClear()
{
}
