
#pragma once
#include "yaUIBase.h"

namespace ya {

	class Map_Gate : public UIBase
	{
	public:
		Map_Gate(eUIType type);
		~Map_Gate();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;
	};
}

