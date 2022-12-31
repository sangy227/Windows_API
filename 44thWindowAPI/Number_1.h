#pragma once
#include "yaUIBase.h"

namespace ya {

	class Number_1 : public UIBase
	{
	public:
		Number_1(eUIType type);
		~Number_1();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;
	};
}