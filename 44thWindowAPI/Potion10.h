

#pragma once
#include "UIItem.h"

namespace ya {
	class Potion10 : public UIItem
	{
	public:
		Potion10(eUIType type);
		~Potion10();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}