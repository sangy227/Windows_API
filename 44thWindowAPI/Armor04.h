

#pragma once
#include "UIItem.h"

namespace ya {
	class Armor04 : public UIItem
	{
	public:
		Armor04(eUIType type);
		~Armor04();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}