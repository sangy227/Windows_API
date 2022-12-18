

#pragma once
#include "UIItem.h"

namespace ya {
	class Potion12 : public UIItem
	{
	public:
		Potion12(eUIType type);
		~Potion12();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}