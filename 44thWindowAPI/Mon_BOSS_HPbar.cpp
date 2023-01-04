#include "Mon_BOSS_HPbar.h"
#include "yaImage.h"
#include "Monster_include.h"
#include "yaAniMator.h"
#include "yaResources.h"
#include "yaPlayer.h"

ya::Mon_BOSS_HPbar::Mon_BOSS_HPbar(eUIType type)
	:UIBase(type)
{
}

ya::Mon_BOSS_HPbar::~Mon_BOSS_HPbar()
{
}

void ya::Mon_BOSS_HPbar::OnInit()
{
}

void ya::Mon_BOSS_HPbar::OnActive()
{
}

void ya::Mon_BOSS_HPbar::OnInActive()
{
}

void ya::Mon_BOSS_HPbar::OnTick()
{
}

void ya::Mon_BOSS_HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	if (mTarget == nullptr)
		return;

	Glory_Knight* mGlory_Knight = dynamic_cast<Glory_Knight*>(mTarget);
	int hp = mGlory_Knight->GetHp();
	float xRatio = (hp / 5.0f);


	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f * xRatio, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));

	if (mImage == nullptr)
		return;

	if (mTarget == nullptr)
		return;

	
}

void ya::Mon_BOSS_HPbar::OnClear()
{
}
