

#pragma once
#include "UIItem.h"

namespace ya {
	class Arrow02 : public UIItem
	{
	public:
		Arrow02(eUIType type);
		~Arrow02();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}