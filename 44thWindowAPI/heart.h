
#pragma once
#include "yaUIBase.h"

namespace ya {
	class GameObject;
	class heart : public UIBase
	{
	public:
		heart(eUIType type);
		~heart();

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