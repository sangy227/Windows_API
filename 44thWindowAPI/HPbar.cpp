#include "HPbar.h"
#include "yaImage.h"
#include "yaPlayer.h"
#include "yaAniMator.h"
#include "yaResources.h"

ya::HPbar::HPbar(eUIType type)
	:UIBase(type)
{
}

ya::HPbar::~HPbar()
{
}

void ya::HPbar::OnInit()
{
}

void ya::HPbar::OnActive()
{
}

void ya::HPbar::OnInActive()
{
}

void ya::HPbar::OnTick()
{
}

void ya::HPbar::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	/*if (mTarget == nullptr)
		return;*/

	//Player* playerObj = dynamic_cast<Player*>(mTarget);
	//int hp = playerObj->GetHp();
	//float xRatio = (hp / 100.0f);

	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 0.8f/* * xRatio */, mImage->GetHeight() * 0.7f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::HPbar::OnClear()
{
}
