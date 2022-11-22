

#pragma once
#include "yaUIBase.h"

namespace ya {

	class Tote_Info : public UIBase
	{
	public:
		Tote_Info(eUIType type);
		~Tote_Info();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;
	};
}