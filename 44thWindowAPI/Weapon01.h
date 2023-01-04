
#pragma once
#include "UIItem.h"

namespace ya {
	class Weapon01 : public UIItem
	{
	public:
		Weapon01(eUIType type);
		~Weapon01();

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