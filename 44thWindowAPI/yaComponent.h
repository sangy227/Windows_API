#pragma once
#include "yaEntity.h"
#include "Common.h"

namespace ya {
	class GameObject;
	class Component : public Entity
	{
	public:
		friend class GameObject;
		Component(eComponentType mType);
		Component() = delete;
		virtual~Component();

		virtual void Tick();
		virtual void Render(HDC hdc);

		GameObject* GetOwner() { return mOwner; }
		void SetOwnder(GameObject* owner) { mOwner = owner; }

	private:
		const eComponentType mType;
		GameObject* mOwner;
	};
}

