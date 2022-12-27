
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


		UINT SetPrevPos(UINT pos) { return mPrevpos = pos; }
		int SetEnemiePos(int pos) { return mEnemiepos = pos; }
		UINT SetDistancePos(UINT init) { return mDistance = init; }


		void Distance(Vector2 mPrevpos, Vector2 mPos, UINT mDistance);
	private:
		Event mOnClick;
		bool mbMouseOn;

		UINT mPrevpos;
		int mEnemiepos;
		UINT mDistance;

	};
}