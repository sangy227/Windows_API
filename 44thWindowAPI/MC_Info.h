
#pragma once
#include "yaUIBase.h"

namespace ya {

	class MC_Info : public UIBase
	{
	public:
		MC_Info(eUIType type);
		~MC_Info();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;



	};
}