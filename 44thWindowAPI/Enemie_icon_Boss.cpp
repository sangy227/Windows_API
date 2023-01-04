#include "Enemie_icon_Boss.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "Map_Player_icon.h"
#include "yaGameObject.h"
#include "yaPlayer.h"
#include "yaScene.h"

ya::Enemie_icon_Boss::Enemie_icon_Boss(eUIType type)
	:UIBase(type)
{
	mOnClick = std::bind(&Enemie_icon_Boss::Click, this);
}

ya::Enemie_icon_Boss::~Enemie_icon_Boss()
{
}

void ya::Enemie_icon_Boss::OnInit()
{
}

void ya::Enemie_icon_Boss::OnActive()
{
}

void ya::Enemie_icon_Boss::OnInActive()
{
}

void ya::Enemie_icon_Boss::OnTick()
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

void ya::Enemie_icon_Boss::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 5.0f, mImage->GetHeight() * 5.0f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Enemie_icon_Boss::OnClear()
{
}

void ya::Enemie_icon_Boss::Click()
{
	Map_Player_icon* playerUi = UIManager::GetUiInstant<Map_Player_icon>(eUIType::Map_Player_icon);


	Player* miniPlayer = Scene::player;
	miniPlayer->Player_Move();

	Vector2 enemie_icon = GetPos();
	playerUi->SetEnemiePos(enemie_icon.x);


	mIconState = Player_Icon_Move::LEFT2;
	GameObject::mBgStatus = ya::GameObject::BgStatus::MOVE;
}
