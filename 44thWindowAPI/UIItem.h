#pragma once
#include "yaUIBase.h"

namespace ya {

	class UIItem : public UIBase
	{
	public:
		static std::vector<std::vector<UIItem*>> mInventories;

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

	protected:
		Vector2 CalculateIndex(Vector2 pos);
		Vector2 CalculateIndexPos(Vector2 Index);

		UINT mXarrIndex;
		UINT mYarrIndex;

		Event mOnClick;
		bool mbMouseOn;
		Vector2 mPrevMousePos;
		Vector2 mPrevClickPos;

	private:
		const UINT row = 5;
		const UINT coulmn = 11;
		Vector2 mPrevIndex;
	};
}