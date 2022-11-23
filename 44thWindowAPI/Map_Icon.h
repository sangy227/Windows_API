
#pragma once
#include "yaUIBase.h"

namespace ya {

	class Map_Icon : public UIBase
	{
	public:
		Map_Icon(eUIType type);
		~Map_Icon();

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

	};
}