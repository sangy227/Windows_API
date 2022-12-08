#pragma once
#include "yaUIBase.h"
#include "TestSword.h"

namespace ya
{

	class Inventory : public UIBase
	{
	public:
		Inventory(eUIType type);
		~Inventory();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();

	private:
		const UINT row = 5;
		const UINT coulmn = 11;

		Event mOnClick;
		bool mbMouseOn;

		std::vector<std::vector<UIItem*>> mInventories;
	};
}