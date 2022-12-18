
#pragma once
#include "UIItem.h"

namespace ya {
	class Dagger04 : public UIItem
	{
	public:
		Dagger04(eUIType type);
		~Dagger04();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}