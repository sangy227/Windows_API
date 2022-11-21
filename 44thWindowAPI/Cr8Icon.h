
#pragma once
#include "yaUIBase.h"

namespace ya {

	class Cr8Icon : public UIBase
	{
	public:
		Cr8Icon(eUIType type);
		~Cr8Icon();

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