#pragma once
#include "yaGameObject.h"

namespace ya {
	class Missile : public GameObject
	{
	public:
		Missile();
		virtual ~Missile();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

	private:

	};

}

