#include "UIItem.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaUIManager.h"
#include "yaCamera.h"

namespace ya {
	 std::vector<std::vector<UIItem*>> UIItem::mInventories;

	UIItem::UIItem(eUIType type)
		:UIBase(type)
		,mXarrIndex(0)
		,mYarrIndex(0)
	{
		//mOnClick = std::bind(&UIItem::Click, this);
		//mPrevPos = GetScreenPos();
	}
	UIItem::~UIItem()
	{
	}
	void UIItem::OnInit()
	{
		mInventories.resize(row);
		for (size_t i = 0; i < row; i++)
			mInventories[i].resize(coulmn);
	}
	void UIItem::OnActive()
	{
	}
	void UIItem::OnInActive()
	{
	}
	void UIItem::OnTick()
	{
		
		int a = 0;
	
	}
	void UIItem::OnRender(HDC hdc)
	{
		
	}
	void UIItem::OnClear()
	{
	}
	void UIItem::Click()
	{
		
	}

	Vector2 UIItem::CalculateIndex(Vector2 pos)
	{
		float width = 399.0f;
		float hegiht = 51.0f;

		Vector2 start(399.0f, 51.0f);
		for (size_t y = 0; y < row; y++)
		{
			for (size_t x = 0; x < coulmn; x++)
			{
				Vector2 indexPos;
				indexPos.x = 77.0f * (x +1) +width;
				indexPos.y = 77.0f * (y +1) +hegiht;

				if (indexPos.x < pos.x && indexPos.x + 77.0f > pos.x
					&& indexPos.y < pos.y && indexPos.y + 77.0f > pos.y)
				{
					return Vector2(x, y);
				}
			}
		}

		//return Vector2(-1.0f, -1.0f);
		return mPrevClickPos;
	}

	Vector2 UIItem::CalculateIndexPos(Vector2 pos)
	{
		float width = 399.0f;
		float hegiht = 51.0f;

		Vector2 start(399.0f, 51.0f);
		for (size_t y = 0; y < row; y++)
		{
			for (size_t x = 0; x < coulmn; x++)
			{
				Vector2 indexPos;
				indexPos.x = 77.0f * (x) + width;
				indexPos.y = 77.0f * (y) + hegiht;

				if (indexPos.x < pos.x && indexPos.x + 77.0f > pos.x
					&& indexPos.y < pos.y && indexPos.y + 77.0f > pos.y)
				{
					return Vector2(indexPos);
				}
			}
		}

		//return Vector2(-1.0f, -1.0f);
		return mPrevClickPos;

	}
}