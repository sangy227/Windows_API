
#pragma once
#include "yaUIBase.h"

namespace ya {

	class Cr8_Info : public UIBase
	{
	public:
		Cr8_Info(eUIType type);
		~Cr8_Info();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;
	};
}