
#pragma once
#include "yaUIBase.h"

namespace ya {

	class Number_0 : public UIBase
	{
	public:
		Number_0(eUIType type);
		~Number_0();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;
	};
}