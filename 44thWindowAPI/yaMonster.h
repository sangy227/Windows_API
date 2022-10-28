#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Monster : public GameObject
	{
	public:
		Monster();
		~Monster();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;


	private:
		Image* mImage;
	};

}