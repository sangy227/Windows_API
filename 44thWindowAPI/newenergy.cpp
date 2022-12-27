#include "newenergy.h"
#include "yaImage.h"
#include "yaPlayer.h"
#include "yaAniMator.h"
#include "yaResources.h"


ya::newenergy::newenergy(eUIType type)
	:UIBase(type)
{
}

ya::newenergy::~newenergy()
{
}

void ya::newenergy::OnInit()
{
}

void ya::newenergy::OnActive()
{
}

void ya::newenergy::OnInActive()
{
}

void ya::newenergy::OnTick()
{
}

void ya::newenergy::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	/*if (mTarget == nullptr)
		return;*/

	Player* playerObj = dynamic_cast<Player*>(mTarget);


	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth()*2.0f, mImage->GetHeight()*2.0f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::newenergy::OnClear()
{
}
