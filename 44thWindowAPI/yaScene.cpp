#include "yaScene.h"
#include "yaGameObject.h"

namespace ya {


	Scene::Scene()
	{
	}

	Scene::~Scene()
	{
		for (size_t i = 0; i < mObject.size(); i++)
		{
			delete mObject[i];
			mObject[i] = nullptr;
		}
	}

	void Scene::Initialize()
	{
		for (size_t i = 0; i < mObject.size(); i++)
		{
			mObject[i]->Initialize();
		}
	}

	void Scene::Tick()
	{
		for (size_t i = 0; i < mObject.size(); i++)
		{
			mObject[i]->Tick();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (size_t i = 0; i < mObject.size(); i++)
		{
			mObject[i]->Render(hdc);
		}
	}

	void Scene::Enter()
	{
	}

	void Scene::Exit()
	{
	}

	void Scene::AddGameObject(GameObject* object)
	{
		if (object == nullptr)
			return;

		mObject.push_back(object);
	}

}