#include "heart.h"
#include "yaImage.h"
#include "yaPlayer.h"
#include "yaAniMator.h"
#include "yaResources.h"

ya::heart::heart(eUIType type)
	:UIBase(type)
{
}

ya::heart::~heart()
{
}

void ya::heart::OnInit()
{
}

void ya::heart::OnActive()
{
}

void ya::heart::OnInActive()
{
}

void ya::heart::OnTick()
{

}

void ya::heart::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	/*if (mTarget == nullptr)
		return;*/

	Player* playerObj = dynamic_cast<Player*>(mTarget);


	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth()*1.5f, mImage->GetHeight()* 1.5f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::heart::OnClear()
{
}
