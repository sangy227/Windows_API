
#pragma once
#include "yaUIBase.h"
#include "yaGameObject.h"
namespace ya {
	class GameObject;
	class Mon11_HPbar : public UIBase
	{
	public:
		Mon11_HPbar(eUIType type);
		~Mon11_HPbar();

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