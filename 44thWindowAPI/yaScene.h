#pragma once
#include "Common.h"
#include "yaEntity.h"

namespace ya {

	class GameObject;
	class Scene : public Entity
	{
	public:

		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		virtual void Enter();
		virtual void Exit();

		void AddGameObject(GameObject* object);

	private:
		std::vector<GameObject*> mObject;

	};
}

