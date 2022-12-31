#include "newenergy.h"
#include "yaImage.h"
#include "yaPlayer.h"
#include "yaAniMator.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaUIManager.h"

ya::newenergy::newenergy(eUIType type)
	:UIItem(type)
	, eNumber_count(eNumber::Number0)
	
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
	mPrevNumber_count = mmNumber_count;

	if (KEY_DOWN(eKeyCode::UP))
	{
		mmNumber_count++;

		if (mmNumber_count > 9)
			mmNumber_count = 9;
		Number_chenge();
	}

	if (KEY_DOWN(eKeyCode::DOWN))
	{
		mmNumber_count--;

		if (mmNumber_count < 0)
			mmNumber_count = 0;

		Number_chenge();
	}

	
	
	

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

void ya::newenergy::Number_chenge()
{
	UIManager::Pop(eUIType::Number_0);
	UIManager::Pop(eUIType::Number_1);
	UIManager::Pop(eUIType::Number_2);
	UIManager::Pop(eUIType::Number_3);
	UIManager::Pop(eUIType::Number_4);
	UIManager::Pop(eUIType::Number_5);
	UIManager::Pop(eUIType::Number_6);
	UIManager::Pop(eUIType::Number_7);
	UIManager::Pop(eUIType::Number_8);
	UIManager::Pop(eUIType::Number_9);

	switch (mmNumber_count)
	{
	case 0:
	{
		UIManager::Push(eUIType::Number_0);
	}
	break;

	case 1:
	{
		UIManager::Push(eUIType::Number_1);
	}
	break;

	case 2:
	{
		UIManager::Push(eUIType::Number_2);
	}
	break;

	case 3:
	{
		UIManager::Push(eUIType::Number_3);
	}
	break;

	case 4:
	{
		UIManager::Push(eUIType::Number_4);
	}
	break;

	case 5:
	{
		UIManager::Push(eUIType::Number_5);
	}
	break;

	case 6:
	{
		UIManager::Push(eUIType::Number_6);
	}
	break;

	case 7:
	{
		UIManager::Push(eUIType::Number_7);
	}
	break;

	case 8:
	{
		UIManager::Push(eUIType::Number_8);
	}
	break;

	case 9:
	{
		UIManager::Push(eUIType::Number_9);
	}
	break;

	default:
		break;
	}
}
