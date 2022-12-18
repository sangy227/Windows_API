
#pragma once
#include "UIItem.h"

namespace ya {
	class Dagger01 : public UIItem
	{
	public:
		Dagger01(eUIType type);
		~Dagger01();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	};
}