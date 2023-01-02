#include "block.h"
#include "yaImage.h"
#include "yaPlayer.h"
#include "yaAniMator.h"
#include "yaResources.h"

ya::block::block(eUIType type)
	:UIBase(type)
{
}

ya::block::~block()
{
}

void ya::block::OnInit()
{
}

void ya::block::OnActive()
{
}

void ya::block::OnInActive()
{
}

void ya::block::OnTick()
{

}

void ya::block::OnRender(HDC hdc)
{
	if (mImage == nullptr)
		return;

	//if (mTarget == nullptr)
		//return;

	//Player* playerObj = dynamic_cast<Player*>(mTarget);


	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 1.5f, mImage->GetHeight() * 1.5f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::block::OnClear()
{
}
