#pragma once
#include "yaGameObject.h"

namespace ya {
	class Missile : public GameObject
	{
	public:
		Missile();
		~Missile();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
		
	private:
		float mSpeed;
	};

}

