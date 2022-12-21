#pragma once

#include "UIItem.h"
namespace ya {

	class TestButton : public UIItem
	{
	public:
		TestButton(eUIType type);
		~TestButton();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	private:
		Event mOnClick;
		bool mbMouseOn;

	};
}