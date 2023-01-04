#include "Ending_icon.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "Map_Player_icon.h"
#include "yaGameObject.h"
#include "yaPlayer.h"
#include "yaScene.h"
ya::Ending_icon::Ending_icon(eUIType type)
	:UIBase(type)
{
	mOnClick = std::bind(&Ending_icon::Click, this);
}


ya::Ending_icon::~Ending_icon()
{
}

void ya::Ending_icon::OnInit()
{
}

void ya::Ending_icon::OnActive()
{
}

void ya::Ending_icon::OnInActive()
{
}

void ya::Ending_icon::OnTick()
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

void ya::Ending_icon::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth()*1.3f, mImage->GetHeight()*1.3f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));
}

void ya::Ending_icon::OnClear()
{
}

void ya::Ending_icon::Click()
{
	Map_Player_icon* playerUi = UIManager::GetUiInstant<Map_Player_icon>(eUIType::Map_Player_icon);


	Player* miniPlayer = Scene::player;
	miniPlayer->Player_Move();

	Vector2 enemie_icon = GetPos();
	playerUi->SetEnemiePos(enemie_icon.y);


	mIconState = Player_Icon_Move::UP2;
	GameObject::mBgStatus = ya::GameObject::BgStatus::MOVE;
}
