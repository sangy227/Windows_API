#include "Mon4_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
ya::Mon4_HPbar::Mon4_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon4_HPbar::~Mon4_HPbar()
{
}

void ya::Mon4_HPbar::OnInit()
{
}

void ya::Mon4_HPbar::OnActive()
{
}

void ya::Mon4_HPbar::OnInActive()
{
}

void ya::Mon4_HPbar::OnTick()
{
}

void ya::Mon4_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	if (mTarget == nullptr)
		return;

	//Gerbil_Ruffian* mGerbil_Ruffian = dynamic_cast<Gerbil_Ruffian*>(mTarget);
	////int hp = mchicken->GetHp();
	//float xRatio = (/*hp*/100 / 100.0f);

	//TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
	//	mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
	//	mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
	//	, RGB(255, 255, 255));

	Gerbil_Ruffian* mGerbil_Ruffian = dynamic_cast<Gerbil_Ruffian*>(mTarget);
	int hp = mGerbil_Ruffian->GetHp();
	float xRatio = (hp / 5.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Mon4_HPbar::OnClear()
{
}
