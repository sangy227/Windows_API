

#pragma once
#include "UIItem.h"

namespace ya {
	class Weapon03 : public UIItem
	{
	public:
		Weapon03(eUIType type);
		~Weapon03();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();


	};
}