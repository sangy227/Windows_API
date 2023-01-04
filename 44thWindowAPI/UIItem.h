#pragma once
#include "yaUIBase.h"

namespace ya {
	//class newenergy;
	class GameObject;
	class Sword;
	class UIItem : public UIBase
	{
	public:
		static std::vector<std::vector<UIItem*>> mInventories;
		static UINT mOverlap;
		static UIItem* thisVariable;

		UIItem(eUIType type);
		~UIItem();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OnInActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		virtual void Click();

		void InventorieArr(Vector2 mPos, Vector2 mPrevClickPos);

		void SetTarget(GameObject* target) { mTarget = target; }

		enum class MONS_TARGET
		{
			monster1,
			monster2,
			monster3,
			monster4,
			monster5,
			monster6,
			monster7,
			monster8,
			monster9,
			monster10,
			monster11,
			monster12,
			monster13,
			monster14,
			monster15,
			monster16,
		};
		
		static MONS_TARGET mMons_target;
	protected:
		template<typename T>
		static T* NewTarget;

	protected:
		

		GameObject* mTarget;
		//newenergy* mEnergyTarget;

		Vector2 CalculateIndex(Vector2 pos);
		Vector2 CalculateIndexPos(Vector2 Index);

		UINT mXarrIndex;
		UINT mYarrIndex;

		

		Event mOnClick;
		bool mbMouseOn;
		bool mbIn_inventory;

		Vector2 mPrevMousePos;
		Vector2 mPrevClickPos;

	private:
		const UINT row = 5;
		const UINT coulmn = 11;
		Vector2 mPrevIndex;

		

	};
}