#include "Weapon02.h"
#include "yaInput.h"
#include "yaImage.h"
#include "yaUIManager.h"
#include "yaCamera.h"
#include "yaPlayer.h"
#include "yaScene.h"
#include "Monster_include.h"
#include "Map_Player_icon.h"
namespace ya {
	Weapon02::Weapon02(eUIType type)
		: UIItem(type)
	{
		mOnClick = std::bind(&Weapon02::Click, this);
		mXarrIndex = 1;
		mYarrIndex = 3;
	}
	Weapon02::~Weapon02()
	{
	}
	void Weapon02::OnInit()
	{
	}
	void Weapon02::OnActive()
	{
	}
	void Weapon02::OnInActive()
	{
	}
	void Weapon02::OnTick()
	{
		//if (mOverlap == 0) {
			//mOverlap = 1;

		Vector2 mousePos = Input::GetMousePos();
		Vector2 size = GetSize();

		if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x * 4.0f
			&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y * 4.0f)
		{
			mbMouseOn = true;
		}
		else
		{
			mbMouseOn = false;
		}

		if (KEY_DOWN(eKeyCode::LBTN) && mbMouseOn)
		{
			mPrevClickPos = GetScreenPos();

			Vector2 mousePos = Input::GetMousePos();
			mPrevMousePos = mousePos;

			thisVariable = this;
			//UIItem::InventorieArr();

			if (Ani_Enable) {
				Select_Monster_Target();

				Player* miniPlayer = Scene::player;
				miniPlayer->Player_Attack();

				mmNumber_count--;
				if (mmNumber_count <= 0) {
					mmNumber_count = 0;
					Ani_Enable = false;
				}

				newenergy* mEnergy = dynamic_cast<newenergy*>(mEnergyTarget);
				mEnergy->Number_chenge();
			}

		}

		if (KEY_PREESE(eKeyCode::LBTN) && mbMouseOn)
		{
			if (thisVariable == this)
				mOnClick();

			

		}

		if (KEY_UP(eKeyCode::LBTN) && mbMouseOn)
		{
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

		//}
	}
	void Weapon02::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 4.0f, mImage->GetHeight() * 4.0f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));

		HBRUSH oldBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
		HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);
		if (mRectEnable == true)
			Rectangle(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			(int)mScreenPos.x + mImage->GetWidth() * 4.0f
			, (int)mScreenPos.y + mImage->GetHeight() * 4.0f);

		SelectObject(hdc, oldPen);
		DeleteObject(bluePen);
		SelectObject(hdc, oldBrush);
	}
	void Weapon02::OnClear()
	{
	}
	void Weapon02::Click()
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
	void Weapon02::Select_Monster_Target()
	{
		switch (mMons_target_int)
		{
		case 1: {
			Monster* mMonster = Map_Player_icon::mons1;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);

			Monster* mMonster2 = Map_Player_icon::mons2;
			int hp2 = mMonster2->GetHp();
			hp2 -= 2;
			mMonster2->SetHp(hp2);
		}
			  break;

		case 2: {
			chicken* mMonster = Map_Player_icon::mons3;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			  break;
		case 3: {
			Gerbil_Ruffian* mMonster = Map_Player_icon::mons4;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			  break;
		case 4: {
			cultist_blade* mMonster = Map_Player_icon::mons5;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			  break;
		case 5: {
			hawk_knight* mMonster = Map_Player_icon::mons6;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			  break;
		case 6: {
			frog_2* mMonster = Map_Player_icon::mons7;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			  break;
		case 7: {
			crossbowman* mMonster = Map_Player_icon::mons8;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			  break;
		case 8: {
			cultist* mMonster = Map_Player_icon::mons9;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			  break;
		case 9: {
			bandit_lord* mMonster = Map_Player_icon::mons10;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			  break;
		case 10: {
			legman* mMonster = Map_Player_icon::mons11;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			   break;
		case 11: {
			Hare_Defender* mMonster = Map_Player_icon::mons12;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			   break;
		case 12: {
			Feral_Badger* mMonster = Map_Player_icon::mons13;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			   break;
		case 13: {
			fire_cobra* mMonster = Map_Player_icon::mons14;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			   break;
		case 14: {
			head_honcho* mMonster = Map_Player_icon::mons15;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			   break;
		case 15: {
			Glory_Knight* mMonster = Map_Player_icon::monsBOSS;
			int hp = mMonster->GetHp();
			hp -= 2;
			mMonster->SetHp(hp);
		}
			   break;
		default:
			break;
		}

	}
}