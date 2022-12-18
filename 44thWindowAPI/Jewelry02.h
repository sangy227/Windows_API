

#pragma once
#include "UIItem.h"

namespace ya {
	class Jewelry02 : public UIItem
	{
	public:
		Jewelry02(eUIType type);
		~Jewelry02();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}