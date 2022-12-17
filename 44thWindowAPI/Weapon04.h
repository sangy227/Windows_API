

#pragma once
#include "UIItem.h"

namespace ya {
	class Weapon04 : public UIItem
	{
	public:
		Weapon04(eUIType type);
		~Weapon04();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();


	};
}