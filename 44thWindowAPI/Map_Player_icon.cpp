#include "Map_Player_icon.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaTime.h"
#include "yaPlayer.h"
#include "Enemie_icon01.h"
#include "Enemie_icon02.h"
#include "Enemie_icon03.h"
#include "Enemie_icon04.h"
#include "Enemie_icon05.h"
#include "yaScene.h"
namespace ya {

int Map_Player_icon::map_ani_count = 0;

}

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
				//UIManager::Pop(eUIType::Enemie_icon01); //pop이 걸렷는데 사라지지 않는이유?

				Enemie_icon01* enemie_icon01 = UIManager::GetUiInstant<Enemie_icon01>(eUIType::Enemie_icon01);
				enemie_icon01->InActive();


				Player* miniPlayer = Scene::player;
				miniPlayer->Player_Idel();
			}
		}
			break;

		case ya::Entity::Player_Icon_Move::DOWN2:
		{
			Vector2 pos = GetPos();
			pos.y += speed * Time::DeltaTime();
			SetPos(pos);
			if (mEnemiepos - GetPos().y < 25)
			{
				GameObject::mBgStatus = ya::GameObject::BgStatus::DEFALUT;
				mIconState = Player_Icon_Move::DEFALUT;
				mEnemiepos = 0;
				//UIManager::Pop(eUIType::Enemie_icon01); //pop이 걸렷는데 사라지지 않는이유?

				
				Enemie_icon05* enemie_icon05 = UIManager::GetUiInstant<Enemie_icon05>(eUIType::Enemie_icon05);
				//enemie_icon05->InActive();
				
				Player* miniPlayer = Scene::player;
				miniPlayer->Player_Idel();
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

				Enemie_icon03* enemie_icon03 = UIManager::GetUiInstant<Enemie_icon03>(eUIType::Enemie_icon03);
				enemie_icon03->InActive();

				Player* miniPlayer = Scene::player;
				miniPlayer->Player_Idel();
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

				Enemie_icon02* enemie_icon02 = UIManager::GetUiInstant<Enemie_icon02>(eUIType::Enemie_icon02);
				enemie_icon02->InActive();

				Player* miniPlayer = Scene::player;
				miniPlayer->Player_Idel();
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

				Enemie_icon04* enemie_icon04 = UIManager::GetUiInstant<Enemie_icon04>(eUIType::Enemie_icon04);
				enemie_icon04->InActive();

				Player* miniPlayer = Scene::player;
				miniPlayer->Player_Idel();
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
