
#pragma once
#include "yaUIBase.h"
#include "Monster_include.h"

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

		static int map_ani_count;
	private:
		Event mOnClick;
		bool mbMouseOn;

		UINT mPrevpos;
		int mEnemiepos;
		UINT mDistance;


		Monster* mons1;
		Monster* mons2;
		chicken* mons3;
		Gerbil_Ruffian* mons4;
		cultist_blade* mons5;
		hawk_knight* mons6;
		frog_2* mons7;
		crossbowman* mons8;
		cultist* mons9;
		bandit_lord* mons10;
		legman* mons11;
		Hare_Defender* mons12;
		Feral_Badger* mons13;
		fire_cobra* mons14;
		head_honcho* mons15;
	};
}