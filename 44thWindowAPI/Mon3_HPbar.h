
#pragma once
#include "yaUIBase.h"
#include "yaGameObject.h"
namespace ya {
	class GameObject;
	class Mon3_HPbar : public UIBase
	{
	public:
		Mon3_HPbar(eUIType type);
		~Mon3_HPbar();

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