#include "target.h"
#include "yaImage.h"
#include "yaPlayer.h"
#include "yaAniMator.h"
#include "yaResources.h"

ya::target::target(eUIType type)
	:UIBase(type)
{
}

ya::target::~target()
{
}

void ya::target::OnInit()
{
}

void ya::target::OnActive()
{
}

void ya::target::OnInActive()
{
}

void ya::target::OnTick()
{
}

void ya::target::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	if (mTarget == nullptr)
		return;

	Player* playerObj = dynamic_cast<Player*>(mTarget);


	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth(), mImage->GetHeight(),
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::target::OnClear()
{
}
