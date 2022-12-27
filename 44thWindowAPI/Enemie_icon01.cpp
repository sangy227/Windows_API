#include "Enemie_icon01.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "Map_Player_icon.h"
#include "yaTime.h"
#include "yaGameObject.h"
#include "yaPlayer.h"

ya::Enemie_icon01::Enemie_icon01(eUIType type)
	:UIBase(type)
{
	mOnClick = std::bind(&Enemie_icon01::Click, this);
}

ya::Enemie_icon01::~Enemie_icon01()
{
}

void ya::Enemie_icon01::OnInit()
{
}

void ya::Enemie_icon01::OnActive()
{
}

void ya::Enemie_icon01::OnInActive()
{
}

void ya::Enemie_icon01::OnTick()
{
	Vector2 mousePos = Input::GetMousePos();
	Vector2 size = GetSize();

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
}

void ya::Enemie_icon01::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth()*5.0f, mImage->GetHeight()*5.0f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Enemie_icon01::OnClear()
{
}

void ya::Enemie_icon01::Click()
{
	Map_Player_icon* playerUi = UIManager::GetUiInstant<Map_Player_icon>(eUIType::Map_Player_icon);

	
	/*Player* miniPlayer;
	miniPlayer->Player_Move();*/

	//Vector2 player_icon = playerUi->GetPos();
	Vector2 enemie_icon = GetPos();
	//UINT deff = enemie_icon.y - player_icon.y;
	
	//playerUi->SetPrevPos(player_icon.y);
	playerUi->SetEnemiePos(enemie_icon.y);
	//playerUi->SetDistancePos(deff);

	mIconState = Player_Icon_Move::DOWN;
	GameObject::mBgStatus = ya::GameObject::BgStatus::MOVE;
	KEY_DOWN(eKeyCode::E);

}
