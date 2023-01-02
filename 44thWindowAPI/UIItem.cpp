#include "UIItem.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaUIManager.h"
#include "yaCamera.h"
#include "Common.h"
#include "newenergy.h"

namespace ya {
	std::vector<std::vector<UIItem*>> UIItem::mInventories;
	UINT UIItem::mOverlap;
	UIItem* UIItem::thisVariable;
	

	UIItem::UIItem(eUIType type)
		:UIBase(type)
		,mbinstail(false)
		//, count(0)
	{
		//mOnClick = std::bind(&UIItem::Click, this);
		//mPrevPos = GetScreenPos();
		mOverlap = 0;
		mInventories.resize(row);
		for (size_t i = 0; i < row; i++)
			mInventories[i].resize(coulmn);

		//count = newenergy::GetNumber_Count();
		

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
		bool out = false;
		if (Index.x >= 11 && Index.y >= 5)
		{
			out = true;
			//mPos = mPrevClickPos;
			//mPos -= mParent->GetPos();
			//SetPos(mPos);
			return;
		}
		//전체 배열을 다 돌면서 있는지 확인
		//this가 있으면 인벤토리안에서 자리 이동 한걸로 확인 가능
		for (UINT y = 0; y < 5; y++)
		{
			for (UINT x = 0; x < 11; x++)
			{
				/* 인벤토리 바깥에 가니까 오류남*/
				/* 인벤토리 바깥에 가니까 오류남*/
				/* 인벤토리 바깥에 가니까 오류남*/

				//이거는 자리이동 한뒤 , 원래있던자리에 NULL만들기
				if (mInventories[y][x] == this)
				{
					mInventories[y][x] = NULL;
				}
				
				//이거는 자리이동 한곳에 이미 다른게 있으면 다시 돌아가기
				// 이거왜 안될까
				//배열이 넘어가면 에외처리 위에서
				if (!(mInventories[Index.y][Index.x] == NULL))
				{
					mPos = mPrevClickPos;
					mPos -= mParent->GetPos();
					SetPos(mPos);
				}
			}
		}
		//새로운 자리에 배열 this 로 집어넣기

		
		if (Index.y + mYarrIndex <= 4 && Index.x + mXarrIndex <=10)
		{
			for (UINT y = 0; y < this->mYarrIndex; y++)
			{
				for (UINT x = 0; x < this->mXarrIndex; x++)
				{
					/*if (Index.x + x >= 11 && Index.y+y >= 5)
					{
						return;
					}*/
					mInventories[Index.y + y][Index.x + x] = this;
					this->mbinstail = true;

					//아이템 bool변수를 만들어서 왓다 갔다 해버리기
				}
			}
		}

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