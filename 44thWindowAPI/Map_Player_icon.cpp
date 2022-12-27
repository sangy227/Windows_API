#include "Map_Player_icon.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaTime.h"
#include "yaPlayer.h"

ya::Map_Player_icon::Map_Player_icon(eUIType type)
	:UIBase(type)
	, mPrevpos(0)
	, mEnemiepos(0)
	, mDistance(0)
{
	mOnClick = std::bind(&Map_Player_icon::Click, this);
}

ya::Map_Player_icon::~Map_Player_icon()
{
}

void ya::Map_Player_icon::OnInit()
{
}

void ya::Map_Player_icon::OnActive()
{
}

void ya::Map_Player_icon::OnInActive()
{
}

void ya::Map_Player_icon::OnTick()
{
	Vector2 mousePos = Input::GetMousePos();
	Vector2 size = GetSize();
	
	UINT speed = 200;
	

	if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x * 5.0f
		&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y * 5.0f)
	{
		mbMouseOn = true;
	}
	else
	{
		mbMouseOn = false;
	}

	if (KEY_DOWN(eKeyCode::LBTN) && mbMouseOn)
	{
		mOnClick();
	}

	if (KEY_DOWN(eKeyCode::S))
	{
		mIconState = Player_Icon_Move::DEFALUT;
	}
	
	//mIconState = Player_Icon_Move::DOWN;

	/*if (mprevpos.y + 200.0f < GEtpos().y)
	{

	}*/
	
	//Distance();
	//if (!(mIconState == Player_Icon_Move::DEFALUT))
	//{
	//	if (mEnemiepos - GetPos().y < 25)
	//	{
	//		mIconState = Player_Icon_Move::DEFALUT;
	//		mEnemiepos = 0;
	//	}

	//	
	//}
	

	switch (mIconState)
	{
		case ya::Entity::Player_Icon_Move::DOWN:
		{
			Vector2 pos = GetPos();
			pos.y += speed * Time::DeltaTime();
			SetPos(pos);
			if (mEnemiepos - GetPos().y < 25)
			{
				GameObject::mBgStatus = ya::GameObject::BgStatus::DEFALUT;
				mIconState = Player_Icon_Move::DEFALUT;
				mEnemiepos = 0;
				UIManager::Pop(eUIType::Enemie_icon01); //pop이 걸렷는데 사라지지 않는이유?
			}
		}
			break;
		case ya::Entity::Player_Icon_Move::UP:
		{
			Vector2 pos = GetPos();
			pos.y -= speed * Time::DeltaTime();
			SetPos(pos);
			if (mEnemiepos - GetPos().y > 25)
			{
				GameObject::mBgStatus = ya::GameObject::BgStatus::DEFALUT;
				mIconState = Player_Icon_Move::DEFALUT;
				mEnemiepos = 0;
			}
		}
			break;
		case ya::Entity::Player_Icon_Move::LEFT:
		{
			Vector2 pos = GetPos();
			pos.x -= speed * Time::DeltaTime();
			SetPos(pos);
			if (mEnemiepos - GetPos().x > 25)
			{
				GameObject::mBgStatus = ya::GameObject::BgStatus::DEFALUT;
				mIconState = Player_Icon_Move::DEFALUT;
				mEnemiepos = 0;
			}
		}
			break;
		case ya::Entity::Player_Icon_Move::RIGHT:
		{
			Vector2 pos = GetPos();
			pos.x += speed * Time::DeltaTime();
			SetPos(pos);
			if (mEnemiepos - GetPos().x < 25)
			{
				GameObject::mBgStatus = ya::GameObject::BgStatus::DEFALUT;
				mIconState = Player_Icon_Move::DEFALUT;
				mEnemiepos = 0;
			}
		}
		break;
		default:
			break;
	}
}

void ya::Map_Player_icon::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 5.0f, mImage->GetHeight() * 5.0f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Map_Player_icon::OnClear()
{
}

void ya::Map_Player_icon::Click()
{
	int a = 0;
}

void ya::Map_Player_icon::Distance(Vector2 mPrevpos, Vector2 mPos, UINT mDistance)
{
	//mIconState = Player_Icon_Move::DOWN;

	/*if (mprevpos.y + 200.0f < GEtpos().y)
	{

	}*/
}
