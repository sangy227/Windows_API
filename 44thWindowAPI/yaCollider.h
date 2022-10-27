#pragma once
#include "yaComponent.h"

namespace ya
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual void Tick() override;

	private:


	};
}
