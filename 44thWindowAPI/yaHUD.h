#pragma once
#include "yaUIBase.h"

namespace ya {
	class GameObject;
	class HUD : public UIBase
	{
		HUD(eUIType type);
		~HUD();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OninActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		void SetTarget(GameObject* target) { mTarget = target; }
	private:
		GameObject* mTarget;
	};
}
