#include "Potion07.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaCamera.h"
#include "yaPlayer.h"
#include "yaScene.h"
#include "yaSound.h"
#include "yaSoundManager.h"
#include "yaScene.h"
ya::Potion07::Potion07(eUIType type)
	: UIItem(type)
{
	mOnClick = std::bind(&Potion07::Click, this);
	mXarrIndex = 2;
	mYarrIndex = 1;
}

ya::Potion07::~Potion07()
{
}

void ya::Potion07::OnInit()
{
}

void ya::Potion07::OnActive()
{
}

void ya::Potion07::OnInActive()
{
}

void ya::Potion07::OnTick()
{
	Vector2 mousePos = Input::GetMousePos();
	Vector2 size = GetSize();

	if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x * 4.0f
		&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y * 3.5f)
	{
		mbMouseOn = true;
	}
	else
	{
		mbMouseOn = false;
	}

	if (KEY_DOWN(eKeyCode::LBTN) && mbMouseOn)
	{
		Sound* mbSound = Scene::mSound[3];
		if (Ani_Enable == false)
			mbSound->Play(false);

		mPrevClickPos = GetScreenPos();

		Vector2 mousePos = Input::GetMousePos();
		mPrevMousePos = mousePos;

		thisVariable = this;
		//UIItem::InventorieArr();

		if (Ani_Enable) {
			Player* miniPlayer = Scene::player;
			miniPlayer->Player_useitem();

			mmNumber_count--;
			if (mmNumber_count <= 0) {
				mmNumber_count = 0;
				Ani_Enable = false;
			}

			newenergy* mEnergy = dynamic_cast<newenergy*>(mEnergyTarget);
			mEnergy->Number_chenge();

			int hp = miniPlayer->GetHp();
			hp++;
			if (hp >= 6)
				hp = 5;
			miniPlayer->SetHp(hp);
		}
	}

	if (KEY_PREESE(eKeyCode::LBTN) && mbMouseOn)
	{
		if (thisVariable == this)
			mOnClick();

	}

	if (KEY_UP(eKeyCode::LBTN) && mbMouseOn)
	{
		Sound* mbSound = Scene::mSound[3];
		if (Ani_Enable == false)
			mbSound->Play(false);

		thisVariable = NULL;
		Vector2 pos = GetScreenPos();

		UIItem::InventorieArr(pos, mPrevClickPos);

		if (399.0f < pos.x && 1257.0f > pos.x
			&& 51.0f < pos.y && 441.0f > pos.y)
		{
			pos = CalculateIndexPos(pos);
			pos -= mParent->GetPos();
			SetPos(pos);

			//mOverlap = 0;
		}
		else
		{
			//인벤토리 바깥으로 벗어난다면 다시 원상복귀로 돌아가는 문법
			/*pos = mPrevClickPos;
			pos -= mParent->GetPos();
			SetPos(pos);*/
			//mOverlap = 0;
		}
	}
}

void ya::Potion07::OnRender(HDC hdc)
{
	TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		mImage->GetWidth() * 4.0f, mImage->GetHeight() * 3.5f,
		mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		, RGB(255, 255, 255));

	HBRUSH oldBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
	HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);

	if (mRectEnable == true)
		Rectangle(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
		(int)mScreenPos.x + mImage->GetWidth() * 4.0f
		, (int)mScreenPos.y + mImage->GetHeight() * 3.5f);

	SelectObject(hdc, oldPen);
	DeleteObject(bluePen);
	SelectObject(hdc, oldBrush);
}

void ya::Potion07::OnClear()
{
}

void ya::Potion07::Click()
{
	Vector2 mousePos = Input::GetMousePos();

	// 마우스 드래그 이동
	if (mPrevMousePos.x != 0.0f && mPrevMousePos.y != 0.0f)
	{
		Vector2 pos = GetPos();

		//Vector2 idx = CalculateIndex(pos);

		Vector2 distance = mousePos - mPrevMousePos;
		pos.x += distance.x;
		pos.y += distance.y;


		//pos = CalculateIndexPos(pos);
		SetPos(pos);
	}

	mPrevMousePos = mousePos;
}
