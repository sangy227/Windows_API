

#pragma once
#include "yaUIBase.h"

namespace ya {

	class Ending_icon : public UIBase
	{
	public:
		Ending_icon(eUIType type);
		~Ending_icon();

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