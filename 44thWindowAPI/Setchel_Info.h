
#pragma once
#include "yaUIBase.h"

namespace ya {

	class Setchel_Info : public UIBase
	{
	public:
		Setchel_Info(eUIType type);
		~Setchel_Info();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;
	};
}