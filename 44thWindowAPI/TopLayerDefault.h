
#pragma once
#include "yaUIBase.h"

namespace ya {

	class TopLayerDefault : public UIBase
	{
	public:
		TopLayerDefault(eUIType type);
		~TopLayerDefault();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;
	};
}
