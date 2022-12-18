


#pragma once
#include "UIItem.h"

namespace ya {
	class Bow02 : public UIItem
	{
	public:
		Bow02(eUIType type);
		~Bow02();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}