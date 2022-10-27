#pragma once
#include "yaGameObject.h"

namespace ya {
	class Image;
	class Player : public GameObject
	{
	public:
		Player();
		~Player();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;
		
	private:
		float mSpeed;
		Image* mImage;
		
	};
}	

