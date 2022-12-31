#pragma once
#include "yaUIBase.h"

namespace ya {

	class Number_8 : public UIBase
	{
	public:
		Number_8(eUIType type);
		~Number_8();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;
	};
}