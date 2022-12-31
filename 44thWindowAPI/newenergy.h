
#pragma once
#include "UIItem.h"

namespace ya {
	class GameObject;
	class newenergy : public UIItem
	{
	public:
		newenergy(eUIType type);
		~newenergy();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		void SetTarget(GameObject* target) { mTarget = target; }

		//int GetNumber_Count() { return mmNumber_count; }
		//void SetNumber_Count(int number_count) { mmNumber_count = number_count; }

		void Number_chenge();

		enum eNumber //만들었는데 안씀
		{
			Number0,
			Number1,
			Number2,
			Number3,
			Number4,
			Number5,
			Number6,
			Number7,
			Number8,
			Number9,
		};

	private:
		int mPrevNumber_count;
		GameObject* mTarget;
		eNumber eNumber_count;
	};
}