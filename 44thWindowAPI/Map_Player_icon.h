
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

		void Battle_bgm();
		void end_battle();

		void Distance(Vector2 mPrevpos, Vector2 mPos, UINT mDistance);

		static int map_ani_count;
		static Monster* mons1;
		static Monster* mons2;
		static chicken* mons3;
		static Gerbil_Ruffian* mons4;
		static cultist_blade* mons5;
		static hawk_knight* mons6;
		static frog_2* mons7;
		static crossbowman* mons8;
		static cultist* mons9;
		static bandit_lord* mons10;
		static legman* mons11;
		static Hare_Defender* mons12;
		static Feral_Badger* mons13;
		static fire_cobra* mons14;
		static head_honcho* mons15;
		static Glory_Knight* monsBOSS;
	protected:

	private:
		Event mOnClick;
		bool mbMouseOn;

		UINT mPrevpos;
		int mEnemiepos;
		UINT mDistance;


	};
}