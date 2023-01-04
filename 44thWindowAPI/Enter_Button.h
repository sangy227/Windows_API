

#pragma once

#include "UIItem.h"
#include "Map_Player_icon.h"

namespace ya {
	class Player;
	class Enter_Button : public Map_Player_icon
	{
	public:
		Enter_Button(eUIType type);
		~Enter_Button();

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
		
		Player* mPlayer;
	};
}
