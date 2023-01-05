#include "yaScene.h"
#include "yaGameObject.h"
#include "yaSceneManager.h"
#include "yaCollisionManager.h"
#include "yaResource.h"
#include "yaResources.h"
#include "yaSound.h"
#include "yaSoundManager.h"

namespace ya {
	Player* Scene::player = nullptr;
	Sound* Scene::mSound[20] = {};

	Scene::Scene()
	{
		SceneManager::SetPlayScene(this);
		mObjects.resize(_COLLIDER_LAYER);

		//mImages[0] = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Player\\MC\\Rogue\\mc_idle-1.bmp");
		mSound[0] = Resources::Load<Sound>(L"bph_game_title", L"..\\Resources\\bgm\\bph_game_title.wav");
		mSound[1] = Resources::Load<Sound>(L"menuBlip", L"..\\Resources\\bgm\\menuBlip.wav");
		mSound[2] = Resources::Load<Sound>(L"roaming_1", L"..\\Resources\\bgm\\roaming_1.wav");
		mSound[2]->SetVolume(10.0f);
		mSound[3] = Resources::Load<Sound>(L"pickup", L"..\\Resources\\bgm\\pickup.wav");
		mSound[4] = Resources::Load<Sound>(L"hit", L"..\\Resources\\bgm\\hit.wav");
		mSound[5] = Resources::Load<Sound>(L"enemy_hit", L"..\\Resources\\bgm\\enemy_hit.wav");
		mSound[6] = Resources::Load<Sound>(L"addShield", L"..\\Resources\\bgm\\addShield.wav");
		mSound[7] = Resources::Load<Sound>(L"heal", L"..\\Resources\\bgm\\heal.wav");
		mSound[8] = Resources::Load<Sound>(L"playerHit", L"..\\Resources\\bgm\\playerHit.wav");
		mSound[9] = Resources::Load<Sound>(L"enemy_die", L"..\\Resources\\bgm\\enemy_die.wav");
		mSound[10] = Resources::Load<Sound>(L"moveHere", L"..\\Resources\\bgm\\moveHere.wav");

		mSound[11] = Resources::Load<Sound>(L"combat_start", L"..\\Resources\\bgm\\combat_start.wav");
		mSound[12] = Resources::Load<Sound>(L"battle", L"..\\Resources\\bgm\\battle.wav");
		mSound[12]->SetVolume(10.0f);
		mSound[13] = Resources::Load<Sound>(L"battle2", L"..\\Resources\\bgm\\battle2.wav");
		mSound[13]->SetVolume(10.0f);

		mSound[14] = Resources::Load<Sound>(L"game_over", L"..\\Resources\\bgm\\game_over.wav");
		mSound[14]->SetVolume(40.0f);

		//game_over
	}

	Scene::~Scene()
	{
		for (size_t y = 0; y < _COLLIDER_LAYER; y++)
		{
			for (size_t x = 0; x < mObjects[y].size(); x++)
			{
				delete mObjects[y][x];
				mObjects[y][x] = nullptr;
			}
		}
		
	}

	void Scene::Initialize()
	{
	
		for (size_t y = 0; y < _COLLIDER_LAYER; y++)
		{
			for (size_t x = 0; x < mObjects[y].size(); x++)
			{
				if (mObjects[y][x] == nullptr)
					continue;
				if (mObjects[y][x]->IsDeath())
					continue;

				mObjects[y][x]->Initialize();
				
			}
		}
	}

	void Scene::Tick()
	{
		
		for (size_t y = 0; y < _COLLIDER_LAYER; y++)
		{
			for (size_t x = 0; x < mObjects[y].size(); x++)
			{
				if (mObjects[y][x] == nullptr)
					continue;
				if (mObjects[y][x]->IsDeath())
					continue;
				mObjects[y][x]->Tick();

			}
		}
	}

	void Scene::Render(HDC hdc)
	{
		
		for (size_t y = 0; y < _COLLIDER_LAYER; y++)
		{
			for (size_t x = 0; x < mObjects[y].size(); x++)
			{
				if (mObjects[y][x] == nullptr)
					continue;
				if (mObjects[y][x]->IsDeath())
					continue;

				mObjects[y][x]->Render(hdc);

			}
		}
	}

	void Scene::Enter()
	{
	}

	void Scene::Exit()
	{
		//CollisionManager::Clear();
	}

	void Scene::AddGameObject(GameObject* object,eColliderLayer type)
	{
		if (object == nullptr)
			return;

		mObjects[(UINT)type].push_back(object);
	}

}