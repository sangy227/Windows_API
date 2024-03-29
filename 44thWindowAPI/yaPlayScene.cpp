#include "yaPlayScene.h"
#include "yaPlayer.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"
#include "yaObject.h"

#include "Monster_include.h"

#include "yaCollisionManager.h"
#include "yaGround.h"
#include "yaUIManager.h"
#include "yaHUD.h"
#include "yaButton.h"
#include "yaUIBase.h"

namespace ya {
	
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}


	void PlayScene::Initialize()
	{
		BgImageObject* bg2 = new BgImageObject();
		bg2->SetImage(L"PlayBG2", L"bg2.bmp");
		//bg2->Initialize();
		AddGameObject(bg2, eColliderLayer::BackGround);

		BgImageObject* bg3 = new BgImageObject();
		bg3->SetImage(L"PlayBG3", L"bg2.bmp");
		bg3->Initialize();
		AddGameObject(bg3, eColliderLayer::BackGround);

		//GameObject::mBgStatus = ya::GameObject::BgStatus::MOVE
		//임시방편
		//Player* player = ya::object::Instantiate<Player>(eColliderLayer::Player);

		/*Ground* ground = ya::object::Instantiate<Ground>(eColliderLayer::Ground);
		ground->SetPos(Vector2(600.0f, 900.0f));*/



		
		player = ya::object::Instantiate<Player>(eColliderLayer::Player);



	
		//mons4 = ya::object::Instantiate<axeman>(Vector2{ 1430.0f, 590.0f }, eColliderLayer::Monster);

		//UIManager::Push(eUIType::INVENTORY);


		/*CollisionManager::SetLayer(eColliderLayer::Player, eColliderLayer::Monster, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);*/
	}


	void PlayScene::Tick()
	{
		Scene::Tick();
		


		if (KEY_DOWN(eKeyCode::N))
		{
			SceneManager::ChangeScene(eSceneType::PlayTwo);
		}
		if (KEY_DOWN(eKeyCode::B))
		{

		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		/*int mcount = UIBase::mMons_target_int;
		wchar_t szFloat[50] = {};
		swprintf_s(szFloat, 50, L"%f",mcount);
		int strLen = wcsnlen_s(szFloat, 50);
		TextOut(hdc, 100, 100, szFloat, strLen);*/

		

	}
	void PlayScene::Enter()
	{
		UIManager::Push(eUIType::TopLayerDefault);
		UIManager::Push(eUIType::Map_Icon);
		UIManager::Push(eUIType::Back_Icon);
		UIManager::Push(eUIType::Inventory2);

		UIManager::Push(eUIType::HPbar);
		UIManager::Push(eUIType::heart01);
		UIManager::Push(eUIType::block01);
		
		UIManager::Push(eUIType::newenergy);
		UIManager::Push(eUIType::Number_3);

		//UIManager::Push(eUIType::Ending_Cheese);

		/*UIManager::Push(eUIType::TestButton);
		UIManager::Push(eUIType::TestSword);*/

		/*mons1 = ya::object::Instantiate<Monster>(eColliderLayer::Monster);
		mons2 = ya::object::Instantiate<Monster>(Vector2{ 1250.0f, 770.0f }, eColliderLayer::Monster);
		mons3 = ya::object::Instantiate<chicken>(Vector2{ 1430.0f, 770.0f }, eColliderLayer::Monster);*/


		CollisionManager::SetLayer(eColliderLayer::Player, eColliderLayer::Monster, true);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, true);
		CollisionManager::SetLayer(eColliderLayer::Ground, eColliderLayer::Player, true);

		//UIManager::Push(eUIType::INVENTORY);

		//HUD* hud = UIManager::GetUiInstant<HUD>(eUIType::MP);
		//임시방편 실험용

		//이친구를 전역변수로 만들어서 쓰기 player가 주솟값
		//player = ya::object::Instantiate<Player>(eColliderLayer::Player);
		//hud->SetTarget(player);

		
	}
	void PlayScene::Exit()
	{
		CollisionManager::SetLayer(eColliderLayer::Player, eColliderLayer::Monster, false);
		CollisionManager::SetLayer(eColliderLayer::Monster, eColliderLayer::Player_Projecttile, false);
		CollisionManager::SetLayer(eColliderLayer::Ground, eColliderLayer::Player, false);

		//UIManager::Pop(eUIType::INVENTORY);
		
	}
}