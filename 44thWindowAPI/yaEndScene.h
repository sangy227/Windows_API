#pragma once
#include "yaScene.h"


namespace ya {

	class EndScene : public Scene
	{
	public:

		EndScene();
		~EndScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter();
		virtual void Exit();

	private:

	};
}