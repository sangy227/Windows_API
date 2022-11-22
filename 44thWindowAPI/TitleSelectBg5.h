
#pragma once
#include "yaUIBase.h"

namespace ya {

	class TitleSelectBg5 : public UIBase
	{
	public:
		TitleSelectBg5(eUIType type);
		~TitleSelectBg5();

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