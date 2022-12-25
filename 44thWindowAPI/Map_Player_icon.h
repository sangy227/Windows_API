
#pragma once
#include "yaUIBase.h"

namespace ya {

	class Map_Player_icon : public UIBase
	{
	public:
		Map_Player_icon(eUIType type);
		~Map_Player_icon();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();
	private:
		Event mOnClick;
		bool mbMouseOn;

		UINT zero100;
	};
}