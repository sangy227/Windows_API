#include "UIItem.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaUIManager.h"
#include "yaCamera.h"

namespace ya {
	 std::vector<std::vector<UINT>> UIItem::mInventories;

	UIItem::UIItem(eUIType type)
		:UIBase(type)
	{
		//mOnClick = std::bind(&UIItem::Click, this);
		//mPrevPos = GetScreenPos();
		mInventories.resize(row);
		for (size_t i = 0; i < row; i++)
			mInventories[i].resize(coulmn);
	}
	UIItem::~UIItem()
	{
	}
	void UIItem::OnInit()
	{

	}
	void UIItem::OnActive()
	{
	}
	void UIItem::OnInActive()
	{
	}
	void UIItem::OnTick()
	{
		
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

	void UIItem::InventorieArr()
	{

		Vector2 Index = this->CalculateIndex(this->GetPos());
		
		//인벤토리가 클릭될때 원래있던 배열자리 0으로초기화
		if (mInventories[Index.y][Index.x] == 1)
		{
			for (UINT y = 0; y < this->mYarrIndex; y++)
			{
				for (UINT x = 0; x < this->mXarrIndex; x++)
				{
					mInventories[Index.y + y][Index.x + x] = 0;
				}
			}
		}

		//새로운 자리에 배열자리 1로 채워넣기
		for (UINT y = 0; y < this->mYarrIndex; y++)
		{
			for (UINT x = 0; x < this->mXarrIndex; x++)
			{
				mInventories[Index.y + y][Index.x + x] = 1;
			}
		}
		
		
		int a = 0;
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
				indexPos.x = 77.0f * (x) + width;
				indexPos.y = 77.0f * (y) + hegiht;

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