#pragma once
#include "yaScene.h"
#include "yaImage.h"

namespace ya {
	
	class LogoScene : public Scene
	{
	public:

		LogoScene();
		~LogoScene();

		 void Initialize() override;
		 void Tick() override;
		 void Render(HDC hdc) override;


	private:
		Image* Logo;
		
	};
}

