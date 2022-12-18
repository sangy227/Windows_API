

#pragma once
#include "UIItem.h"

namespace ya {
	class Bow03 : public UIItem
	{
	public:
		Bow03(eUIType type);
		~Bow03();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}