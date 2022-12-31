#pragma once
#include "yaUIBase.h"

namespace ya {

	class Number_5 : public UIBase
	{
	public:
		Number_5(eUIType type);
		~Number_5();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;
	};
}