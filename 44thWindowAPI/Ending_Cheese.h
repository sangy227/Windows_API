

#pragma once
#include "yaUIBase.h"

namespace ya {

	class Ending_Cheese : public UIBase
	{
	public:
		Ending_Cheese(eUIType type);
		~Ending_Cheese();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;
	};
}