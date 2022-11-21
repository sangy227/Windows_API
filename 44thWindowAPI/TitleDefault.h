#pragma once
#include "yaUIBase.h"

namespace ya {

	class TitleDefault : public UIBase
	{
	public:
		TitleDefault(eUIType type);
		~TitleDefault();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;



	};
}