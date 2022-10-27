#pragma once
#include "yaEntity.h"
#include "def.h"
namespace ya {
	class Component : public Entity
	{
	public:

		Component(eComponentType mType);
		Component() = delete;
		virtual~Component();

		virtual void Tick() = 0;
		virtual void Render(HDC hdc);

	private:
		const eComponentType mType;
	};
}

