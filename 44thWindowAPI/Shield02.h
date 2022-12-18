

#pragma once
#include "UIItem.h"

namespace ya {
	class Shield02 : public UIItem
	{
	public:
		Shield02(eUIType type);
		~Shield02();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}