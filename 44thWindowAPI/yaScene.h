#pragma once
#include "Common.h"
#include "yaEntity.h"
#include "yaPlayer.h"
#include "yaSound.h"

namespace ya {
	class Sound;
	class Player;
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

		void AddGameObject(GameObject* object,eColliderLayer type);

		std::vector<GameObject*>& GetGameObjects(eColliderLayer type) { return mObjects[(UINT)type]; }
		std::vector<std::vector<GameObject*>>& GetGameObjects() { return mObjects; }


		static Player* player;
		static Sound* mSound[20];
	private:
		//std::vector<GameObject*> mObject;
		std::vector<std::vector<GameObject*>> mObjects;

	
	};
}

