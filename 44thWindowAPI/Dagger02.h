
#pragma once
#include "UIItem.h"

namespace ya {
	class Dagger02 : public UIItem
	{
	public:
		Dagger02(eUIType type);
		~Dagger02();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();

		void Select_Monster_Target();

	};
}