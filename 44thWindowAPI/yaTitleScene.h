#pragma once
#include "yaScene.h"


namespace ya {

	class TitleScene : public Scene
	{
	public:

		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter();
		virtual void Exit();

	private:
	
	};
}