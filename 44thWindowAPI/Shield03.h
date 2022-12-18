
#pragma once
#include "UIItem.h"

namespace ya {
	class Shield03 : public UIItem
	{
	public:
		Shield03(eUIType type);
		~Shield03();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}