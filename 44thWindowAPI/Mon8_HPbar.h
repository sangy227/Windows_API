
#pragma once
#include "yaUIBase.h"
#include "yaGameObject.h"
namespace ya {
	class GameObject;
	class Mon8_HPbar : public UIBase
	{
	public:
		Mon8_HPbar(eUIType type);
		~Mon8_HPbar();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		void SetTarget(GameObject* target) { mTarget = target; }
	private:
		GameObject* mTarget;
	};
}