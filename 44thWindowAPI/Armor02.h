
#pragma once
#include "UIItem.h"

namespace ya {
	class Armor02 : public UIItem
	{
	public:
		Armor02(eUIType type);
		~Armor02();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}