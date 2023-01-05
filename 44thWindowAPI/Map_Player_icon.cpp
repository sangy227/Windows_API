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
#include "Enemie_icon_Boss.h"
#include "Ending_icon.h"

#include "Monster_include.h"
#include "yaObject.h"
#include "HPbar_Include.h"
#include "newenergy.h"
#include "yaUIBase.h"

#include "yaSound.h"
#include "yaSoundManager.h"
#include "yaScene.h"

namespace ya {
	Monster* Map_Player_icon::mons1 = nullptr;
	Monster* Map_Player_icon::mons2 = nullptr;
	chicken* Map_Player_icon::mons3 = nullptr;
	Gerbil_Ruffian* Map_Player_icon::mons4 = nullptr;
	cultist_blade* Map_Player_icon::mons5 = nullptr;
	hawk_knight* Map_Player_icon::mons6 = nullptr;
	frog_2* Map_Player_icon::mons7 = nullptr;
	crossbowman* Map_Player_icon::mons8 = nullptr;
	cultist* Map_Player_icon::mons9 = nullptr;
	bandit_lord* Map_Player_icon::mons10 = nullptr;
	legman* Map_Player_icon::mons11 = nullptr;
	Hare_Defender* Map_Player_icon::mons12 = nullptr;
	Feral_Badger* Map_Player_icon::mons13 = nullptr;
	fire_cobra* Map_Player_icon::mons14 = nullptr;
	head_honcho* Map_Player_icon::mons15= nullptr;
	Glory_Knight* Map_Player_icon::monsBOSS = nullptr;

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
	mons4 = ya::object::Instantiate<Gerbil_Ruffian>(Vector2{ 2250.0f, 770.0f }, eColliderLayer::Monster);
	mons5 = ya::object::Instantiate<cultist_blade>(Vector2{ 2250.0f, 770.0f }, eColliderLayer::Monster);
	mons6 = ya::object::Instantiate<hawk_knight>(Vector2{ 2430.0f, 770.0f }, eColliderLayer::Monster);
	mons7 = ya::object::Instantiate<frog_2>(Vector2{ 2250.0f, 770.0f }, eColliderLayer::Monster);
	mons8 = ya::object::Instantiate<crossbowman>(Vector2{ 2250.0f, 770.0f }, eColliderLayer::Monster);
	mons9 = ya::object::Instantiate<cultist>(Vector2{ 2250.0f, 770.0f }, eColliderLayer::Monster);
	mons10 = ya::object::Instantiate<bandit_lord>(Vector2{ 2250.0f, 770.0f }, eColliderLayer::Monster);
	mons11 = ya::object::Instantiate<legman>(Vector2{ 2250.0f, 770.0f }, eColliderLayer::Monster);
	mons12 = ya::object::Instantiate<Hare_Defender>(Vector2{ 2250.0f, 770.0f }, eColliderLayer::Monster);
	mons13 = ya::object::Instantiate<Feral_Badger>(Vector2{ 2250.0f, 770.0f }, eColliderLayer::Monster);
	mons14 = ya::object::Instantiate<fire_cobra>(Vector2{ 2250.0f, 770.0f }, eColliderLayer::Monster);
	mons15 = ya::object::Instantiate<head_honcho>(Vector2{ 2250.0f, 770.0f }, eColliderLayer::Monster);
	monsBOSS = ya::object::Instantiate<Glory_Knight>(Vector2{ 2250.0f, 770.0f }, eColliderLayer::Monster);
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
				Battle_bgm();

				UIBase::Mons_Remaining = 3;
				mmNumber_count = 3;
				
				newenergy* mEnergy = dynamic_cast<newenergy*>(mEnergyTarget);
				mEnergy->Number_chenge();

				GameObject::mBgStatus = ya::GameObject::BgStatus::DEFALUT;
				mIconState = Player_Icon_Move::DEFALUT;
				mEnemiepos = 0;
				

				Enemie_icon01* enemie_icon01 = UIManager::GetUiInstant<Enemie_icon01>(eUIType::Enemie_icon01);
				enemie_icon01->InActive();


				Player* miniPlayer = Scene::player;
				miniPlayer->Player_Idel();

				mons1 = ya::object::Instantiate<Monster>(eColliderLayer::Monster);
				mons2 = ya::object::Instantiate<Monster>(Vector2{ 1250.0f, 770.0f }, eColliderLayer::Monster);
				mons3 = ya::object::Instantiate<chicken>(Vector2{ 1430.0f, 770.0f }, eColliderLayer::Monster);

				Mon1_HPbar* mMon1_HPbar = UIManager::GetUiInstant<Mon1_HPbar>(eUIType::Mon1_HPbar);
				mMon1_HPbar->SetTarget(mons1);

				Mon2_HPbar* mMon2_HPbar = UIManager::GetUiInstant<Mon2_HPbar>(eUIType::Mon2_HPbar);
				mMon2_HPbar->SetTarget(mons2);

				Mon3_HPbar* mMon3_HPbar = UIManager::GetUiInstant<Mon3_HPbar>(eUIType::Mon3_HPbar);
				mMon3_HPbar->SetTarget(mons3);

				UIManager::Push(eUIType::Mon3_HPbar);
				UIManager::Push(eUIType::Mon2_HPbar);
				UIManager::Push(eUIType::Mon1_HPbar);

				UIManager::Push(eUIType::heart02);
				UIManager::Push(eUIType::heart03);
				UIManager::Push(eUIType::heart04);



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
				Battle_bgm();
				UIBase::Mons_Remaining = 3;

				mmNumber_count = 3;
				newenergy* mEnergy = dynamic_cast<newenergy*>(mEnergyTarget);
				mEnergy->Number_chenge();

				GameObject::mBgStatus = ya::GameObject::BgStatus::DEFALUT;
				mIconState = Player_Icon_Move::DEFALUT;
				mEnemiepos = 0;
				
				Enemie_icon05* enemie_icon05 = UIManager::GetUiInstant<Enemie_icon05>(eUIType::Enemie_icon05);
				enemie_icon05->InActive();
				
				Player* miniPlayer = Scene::player;
				miniPlayer->Player_Idel();

				mons10->Death();
				mons11->Death();
				mons12->Death();

				UIManager::Pop(eUIType::Mon10_HPbar);
				UIManager::Pop(eUIType::Mon11_HPbar);
				UIManager::Pop(eUIType::Mon12_HPbar);

				UIManager::Pop(eUIType::heart02);
				UIManager::Pop(eUIType::heart03);
				UIManager::Pop(eUIType::heart04);

				//mons1->Death();
				/*mons13 = ya::object::Instantiate<Feral_Badger>(eColliderLayer::Monster);
				mons14 = ya::object::Instantiate<fire_cobra>(Vector2{ 1250.0f, 770.0f }, eColliderLayer::Monster);
				mons15 = ya::object::Instantiate<head_honcho>(Vector2{ 1430.0f, 770.0f }, eColliderLayer::Monster);*/
				mons13->SetPos(Vector2{ 1070.0f, 770.0f });
				mons14->SetPos(Vector2{ 1250.0f, 770.0f });
				mons15->SetPos(Vector2{ 1430.0f, 770.0f });


				Mon13_HPbar* mMon13_HPbar = UIManager::GetUiInstant<Mon13_HPbar>(eUIType::Mon13_HPbar);
				mMon13_HPbar->SetTarget(mons13);

				Mon14_HPbar* mMon14_HPbar = UIManager::GetUiInstant<Mon14_HPbar>(eUIType::Mon14_HPbar);
				mMon14_HPbar->SetTarget(mons14);

				Mon15_HPbar* mMon15_HPbar = UIManager::GetUiInstant<Mon15_HPbar>(eUIType::Mon15_HPbar);
				mMon15_HPbar->SetTarget(mons15);

				UIManager::Push(eUIType::Mon13_HPbar);
				UIManager::Push(eUIType::Mon14_HPbar);
				UIManager::Push(eUIType::Mon15_HPbar);

				UIManager::Push(eUIType::heart02);
				UIManager::Push(eUIType::heart03);
				UIManager::Push(eUIType::heart04);
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
				Battle_bgm();

				UIBase::Mons_Remaining = 3;
				mmNumber_count = 3;
				newenergy* mEnergy = dynamic_cast<newenergy*>(mEnergyTarget);
				mEnergy->Number_chenge();

				GameObject::mBgStatus = ya::GameObject::BgStatus::DEFALUT;
				mIconState = Player_Icon_Move::DEFALUT;
				mEnemiepos = 0;

				Enemie_icon03* enemie_icon03 = UIManager::GetUiInstant<Enemie_icon03>(eUIType::Enemie_icon03);
				enemie_icon03->InActive();

				Player* miniPlayer = Scene::player;
				miniPlayer->Player_Idel();

				mons4->Death();
				mons5->Death();
				mons6->Death();

				UIManager::Pop(eUIType::Mon4_HPbar);
				UIManager::Pop(eUIType::Mon5_HPbar);
				UIManager::Pop(eUIType::Mon6_HPbar);

				UIManager::Pop(eUIType::heart02);
				UIManager::Pop(eUIType::heart03);
				UIManager::Pop(eUIType::heart04);

				/*mons7 = ya::object::Instantiate<frog_2>(eColliderLayer::Monster);
				mons8 = ya::object::Instantiate<crossbowman>(Vector2{ 1250.0f, 770.0f }, eColliderLayer::Monster);
				mons9 = ya::object::Instantiate<cultist>(Vector2{ 1430.0f, 770.0f }, eColliderLayer::Monster);*/
				mons7->SetPos(Vector2{ 1070.0f, 770.0f });
				mons8->SetPos(Vector2{ 1250.0f, 770.0f });
				mons9->SetPos(Vector2{ 1430.0f, 770.0f });

				Mon7_HPbar* mMon7_HPbar = UIManager::GetUiInstant<Mon7_HPbar>(eUIType::Mon7_HPbar);
				mMon7_HPbar->SetTarget(mons7);

				Mon8_HPbar* mMon8_HPbar = UIManager::GetUiInstant<Mon8_HPbar>(eUIType::Mon8_HPbar);
				mMon8_HPbar->SetTarget(mons8);

				Mon9_HPbar* mMon9_HPbar = UIManager::GetUiInstant<Mon9_HPbar>(eUIType::Mon9_HPbar);
				mMon9_HPbar->SetTarget(mons9);

				UIManager::Push(eUIType::Mon7_HPbar);
				UIManager::Push(eUIType::Mon8_HPbar);
				UIManager::Push(eUIType::Mon9_HPbar);

				UIManager::Push(eUIType::heart02);
				UIManager::Push(eUIType::heart03);
				UIManager::Push(eUIType::heart04);
			}
		}
			break;
		case ya::Entity::Player_Icon_Move::UP2:
		{
			Vector2 pos = GetPos();
			pos.y -= speed * Time::DeltaTime();
			SetPos(pos);
			if (mEnemiepos - GetPos().y > 25)
			{
				Sound* mbSound2 = Scene::mSound[2];
				mbSound2->Stop(false);

				Sound* mbSound14 = Scene::mSound[14];
				mbSound14->Play(false);

				UIBase::Mons_Remaining = 3;
				mmNumber_count = 3;
				newenergy* mEnergy = dynamic_cast<newenergy*>(mEnergyTarget);
				mEnergy->Number_chenge();

				GameObject::mBgStatus = ya::GameObject::BgStatus::DEFALUT;
				mIconState = Player_Icon_Move::DEFALUT;
				mEnemiepos = 0;

				Enemie_icon_Boss* mEnemie_icon_Boss = UIManager::GetUiInstant<Enemie_icon_Boss>(eUIType::Enemie_icon_Boss);
				mEnemie_icon_Boss->InActive();

				Player* miniPlayer = Scene::player;
				miniPlayer->Player_winsmall();

				monsBOSS->Death();

				UIManager::Pop(eUIType::Mon_BOSS_HPbar);

				UIManager::Pop(eUIType::heart03);

				UIManager::Push(eUIType::Ending_Cheese);


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
				Battle_bgm();

				UIBase::Mons_Remaining = 3;
				mmNumber_count = 3;
				//newenergy::Number_chenge();

				newenergy* mEnergy = dynamic_cast<newenergy*>(mEnergyTarget);
				mEnergy->Number_chenge();

				GameObject::mBgStatus = ya::GameObject::BgStatus::DEFALUT;
				mIconState = Player_Icon_Move::DEFALUT;
				mEnemiepos = 0;

				Enemie_icon02* enemie_icon02 = UIManager::GetUiInstant<Enemie_icon02>(eUIType::Enemie_icon02);
				enemie_icon02->InActive();

				Player* miniPlayer = Scene::player;
				miniPlayer->Player_Idel();

				mons1->Death();
				mons2->Death();
				mons3->Death();

				UIManager::Pop(eUIType::Mon1_HPbar);
				UIManager::Pop(eUIType::Mon2_HPbar);
				UIManager::Pop(eUIType::Mon3_HPbar);

				UIManager::Pop(eUIType::heart02);
				UIManager::Pop(eUIType::heart03);
				UIManager::Pop(eUIType::heart04);

				//mons1->Death();
				/*mons4 = ya::object::Instantiate<Gerbil_Ruffian>(eColliderLayer::Monster);
				mons5 = ya::object::Instantiate<cultist_blade>(Vector2{ 1250.0f, 770.0f }, eColliderLayer::Monster);
				mons6 = ya::object::Instantiate<hawk_knight>(Vector2{ 1430.0f, 770.0f }, eColliderLayer::Monster);*/
				mons4->SetPos(Vector2{ 1070.0f, 770.0f });
				mons5->SetPos(Vector2{ 1250.0f, 770.0f });
				mons6->SetPos(Vector2{ 1430.0f, 770.0f });

				Mon4_HPbar* mMon4_HPbar = UIManager::GetUiInstant<Mon4_HPbar>(eUIType::Mon4_HPbar);
				mMon4_HPbar->SetTarget(mons4);

				Mon5_HPbar* mMon5_HPbar = UIManager::GetUiInstant<Mon5_HPbar>(eUIType::Mon5_HPbar);
				mMon5_HPbar->SetTarget(mons5);

				Mon6_HPbar* mMon6_HPbar = UIManager::GetUiInstant<Mon6_HPbar>(eUIType::Mon6_HPbar);
				mMon6_HPbar->SetTarget(mons6);

				UIManager::Push(eUIType::Mon4_HPbar);
				UIManager::Push(eUIType::Mon5_HPbar);
				UIManager::Push(eUIType::Mon6_HPbar);

				UIManager::Push(eUIType::heart02);
				UIManager::Push(eUIType::heart03);
				UIManager::Push(eUIType::heart04);
			}
		}
			break;
		case ya::Entity::Player_Icon_Move::LEFT2:
		{
			Sound* mbSound2 = Scene::mSound[2];
			mbSound2->Stop(false);

			Sound* mbSound11 = Scene::mSound[11];
			mbSound11->Play(false);

			Sound* mbSound13 = Scene::mSound[13];
			mbSound13->Play(true);

			Vector2 pos = GetPos();
			pos.x -= speed * Time::DeltaTime();
			SetPos(pos);
			if (mEnemiepos - GetPos().x > 25)
			{
				UIBase::Mons_Remaining = 3;
				mmNumber_count = 3;
				newenergy* mEnergy = dynamic_cast<newenergy*>(mEnergyTarget);
				mEnergy->Number_chenge();

				GameObject::mBgStatus = ya::GameObject::BgStatus::DEFALUT;
				mIconState = Player_Icon_Move::DEFALUT;
				mEnemiepos = 0;

				Enemie_icon_Boss* mEnemie_icon_Boss = UIManager::GetUiInstant<Enemie_icon_Boss>(eUIType::Enemie_icon_Boss);
				mEnemie_icon_Boss->InActive();

				Player* miniPlayer = Scene::player;
				miniPlayer->Player_Idel();

				mons13->Death();
				mons14->Death();
				mons15->Death();

				UIManager::Pop(eUIType::Mon13_HPbar);
				UIManager::Pop(eUIType::Mon14_HPbar);
				UIManager::Pop(eUIType::Mon15_HPbar);

				UIManager::Pop(eUIType::heart02);
				UIManager::Pop(eUIType::heart03);
				UIManager::Pop(eUIType::heart04);

				//mons1->Death();
				//monsBOSS = ya::object::Instantiate<Glory_Knight>(Vector2{ 1250.0f, 770.0f }, eColliderLayer::Monster);
				monsBOSS->SetPos(Vector2{ 1250.0f, 770.0f });
				
				Mon_BOSS_HPbar* mon_boss_HPbar = UIManager::GetUiInstant<Mon_BOSS_HPbar>(eUIType::Mon_BOSS_HPbar);
				mon_boss_HPbar->SetTarget(monsBOSS);

			
				UIManager::Push(eUIType::Mon_BOSS_HPbar);

				UIManager::Push(eUIType::heart03);
				
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
				Battle_bgm();

				UIBase::Mons_Remaining = 3;

				mmNumber_count = 3;

				newenergy* mEnergy = dynamic_cast<newenergy*>(mEnergyTarget);
				mEnergy->Number_chenge();


				GameObject::mBgStatus = ya::GameObject::BgStatus::DEFALUT;
				mIconState = Player_Icon_Move::DEFALUT;
				mEnemiepos = 0;

				Enemie_icon04* enemie_icon04 = UIManager::GetUiInstant<Enemie_icon04>(eUIType::Enemie_icon04);
				enemie_icon04->InActive();

				Player* miniPlayer = Scene::player;
				miniPlayer->Player_Idel();

				mons7->Death();
				mons8->Death();
				mons9->Death();

				UIManager::Pop(eUIType::Mon7_HPbar);
				UIManager::Pop(eUIType::Mon8_HPbar);
				UIManager::Pop(eUIType::Mon9_HPbar);

				UIManager::Pop(eUIType::heart02);
				UIManager::Pop(eUIType::heart03);
				UIManager::Pop(eUIType::heart04);

				/*mons10 = ya::object::Instantiate<bandit_lord>(eColliderLayer::Monster);
				mons11 = ya::object::Instantiate<legman>(Vector2{ 1250.0f, 770.0f }, eColliderLayer::Monster);
				mons12 = ya::object::Instantiate<Hare_Defender>(Vector2{ 1430.0f, 770.0f }, eColliderLayer::Monster);*/
				mons10->SetPos(Vector2{ 1070.0f, 770.0f });
				mons11->SetPos(Vector2{ 1250.0f, 770.0f });
				mons12->SetPos(Vector2{ 1430.0f, 770.0f });

				Mon10_HPbar* mMon10_HPbar = UIManager::GetUiInstant<Mon10_HPbar>(eUIType::Mon10_HPbar);
				mMon10_HPbar->SetTarget(mons10);

				Mon11_HPbar* mMon11_HPbar = UIManager::GetUiInstant<Mon11_HPbar>(eUIType::Mon11_HPbar);
				mMon11_HPbar->SetTarget(mons11);

				Mon12_HPbar* mMon12_HPbar = UIManager::GetUiInstant<Mon12_HPbar>(eUIType::Mon12_HPbar);
				mMon12_HPbar->SetTarget(mons12);

				UIManager::Push(eUIType::Mon10_HPbar);
				UIManager::Push(eUIType::Mon11_HPbar);
				UIManager::Push(eUIType::Mon12_HPbar);

				UIManager::Push(eUIType::heart02);
				UIManager::Push(eUIType::heart03);
				UIManager::Push(eUIType::heart04);
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

void ya::Map_Player_icon::Battle_bgm()
{
	Sound* mbSound2 = Scene::mSound[2];
	mbSound2->Stop(false);

	Sound* mbSound11 = Scene::mSound[11];
	mbSound11->Play(false);

	Sound* mbSound12 = Scene::mSound[12];
	mbSound12->Play(true);
}

void ya::Map_Player_icon::end_battle()
{
	Sound* mbSound12 = Scene::mSound[12];
	mbSound12->Stop(false);

	Sound* mbSound2 = Scene::mSound[2];
	mbSound2->Play(true);
}

void ya::Map_Player_icon::Distance(Vector2 mPrevpos, Vector2 mPos, UINT mDistance)
{
	//mIconState = Player_Icon_Move::DOWN;

	/*if (mprevpos.y + 200.0f < GEtpos().y)
	{

	}*/
}
