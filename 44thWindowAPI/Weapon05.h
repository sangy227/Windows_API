
#pragma once
#include "UIItem.h"

namespace ya {
	class Weapon05 : public UIItem
	{
	public:
		Weapon05(eUIType type);
		~Weapon05();

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