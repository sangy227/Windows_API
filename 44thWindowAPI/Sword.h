
#pragma once
#include "UIItem.h"

namespace ya {

	class Sword : public UIItem
	{
	public:
		Sword(eUIType type);
		~Sword();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}