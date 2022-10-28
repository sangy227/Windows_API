#include "yaScene.h"
#include "yaGameObject.h"

namespace ya {


	Scene::Scene()
	{
		mObject.resize(_COLLIDER_LAYER);
	}

	Scene::~Scene()
	{
		for (size_t y = 0; y < _COLLIDER_LAYER; y++)
		{
			for (size_t x = 0; x < mObject[y].size(); x++)
			{
				delete mObject[y][x];
				mObject[y][x] = nullptr;
			}
		}
		
	}

	void Scene::Initialize()
	{
	
		for (size_t y = 0; y < _COLLIDER_LAYER; y++)
		{
			for (size_t x = 0; x < mObject[y].size(); x++)
			{
				if (mObject[y][x] != nullptr )
				{
					mObject[y][x]->Initialize();
				}
				
			}
		}
	}

	void Scene::Tick()
	{
		
		for (size_t y = 0; y < _COLLIDER_LAYER; y++)
		{
			for (size_t x = 0; x < mObject[y].size(); x++)
			{
				if (mObject[y][x] != nullptr)
				{
					mObject[y][x]->Tick();
				}

			}
		}
	}

	void Scene::Render(HDC hdc)
	{
		
		for (size_t y = 0; y < _COLLIDER_LAYER; y++)
		{
			for (size_t x = 0; x < mObject[y].size(); x++)
			{
				if (mObject[y][x] != nullptr)
				{
					mObject[y][x]->Render(hdc);
				}

			}
		}
	}

	void Scene::Enter()
	{
	}

	void Scene::Exit()
	{
	}

	void Scene::AddGameObject(GameObject* object,eColliderLayer type)
	{
		if (object == nullptr)
			return;

		mObject[(UINT)type].push_back(object);
	}

}