

#pragma once
#include "UIItem.h"

namespace ya {
	class Jewelry03 : public UIItem
	{
	public:
		Jewelry03(eUIType type);
		~Jewelry03();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}