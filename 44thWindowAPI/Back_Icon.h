
#pragma once
#include "yaUIBase.h"

namespace ya {

	class Back_Icon : public UIBase
	{
	public:
		Back_Icon(eUIType type);
		~Back_Icon();

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