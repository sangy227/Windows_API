
#pragma once
#include "UIItem.h"

namespace ya {
	class Jewelry01 : public UIItem
	{
	public:
		Jewelry01(eUIType type);
		~Jewelry01();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}