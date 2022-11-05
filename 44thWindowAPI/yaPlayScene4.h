#pragma once
#include "yaScene.h"


namespace ya {
	class chicken;
	class Monster;
	class PlayScene4 : public Scene
	{
	public:

		PlayScene4();
		~PlayScene4();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

		virtual void Enter();
		virtual void Exit();

	private:
		Monster* mons1;
		Monster* mons2;
		chicken* mons3;

	};
}