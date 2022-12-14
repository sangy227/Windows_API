#include "UIItem.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaUIManager.h"
#include "yaCamera.h"
#include "Common.h"
namespace ya {
	 std::vector<std::vector<UIItem*>> UIItem::mInventories;

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

	void UIItem::InventorieArr(Vector2 mPos, Vector2 mPrevClickPos)
	{

		Vector2 Index = this->CalculateIndex(this->GetPos() + mParent->GetPos());
		
		//전체 배열을 다 돌면서 있는지 확인
		//this가 있으면 인벤토리안에서 자리 이동 한걸로 확인 가능
		for (UINT y = 0; y < 5; y++)
		{
			for (UINT x = 0; x < 11; x++)
			{
				//이거는 자리이동 한뒤 , 원래있던자리에 NULL만들기
				if (mInventories[y][x] == this)
				{
					mInventories[y][x] = NULL;
				}
				
				//이거는 자리이동 한곳에 이미 다른게 있으면 다시 돌아가기
				if (!(mInventories[Index.y][Index.x] == NULL))
				{
					mPos = mPrevClickPos;
					mPos -= mParent->GetPos();
					SetPos(mPos);
				}
			}
		}
		//새로운 자리에 배열 this 로 집어넣기
		for (UINT y = 0; y < this->mYarrIndex; y++)
		{
			for (UINT x = 0; x < this->mXarrIndex; x++)
			{
				mInventories[Index.y + y][Index.x + x] = this;
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
				indexPos.x = 77.0f * (x)+width;
				indexPos.y = 77.0f * (y)+hegiht;

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
				indexPos.x = 77.0f * (x)+width;
				indexPos.y = 77.0f * (y)+hegiht;

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