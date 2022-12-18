
#pragma once
#include "UIItem.h"

namespace ya {
	class Armor06 : public UIItem
	{
	public:
		Armor06(eUIType type);
		~Armor06();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}