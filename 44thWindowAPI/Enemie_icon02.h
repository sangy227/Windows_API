
#pragma once
#include "yaUIBase.h"

namespace ya {

	class Enemie_icon02 : public UIBase
	{
	public:
		Enemie_icon02(eUIType type);
		~Enemie_icon02();

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