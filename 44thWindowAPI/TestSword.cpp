#include "TestSword.h"
#include "yaImage.h"
#include "yaInput.h"
#include "yaUIManager.h"
#include "yaCamera.h"
namespace ya {
	UIItem::UIItem(eUIType type)
		:UIBase(type)
	{
		mOnClick = std::bind(&UIItem::Click, this);
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
		Vector2 mousePos = Input::GetMousePos();
		Vector2 size = GetSize();

		if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x * 4.0f
			&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y * 4.0f)
		{
			mbMouseOn = true;
		}
		else
		{
			mbMouseOn = false;
		}

		if (KEY_PREESE(eKeyCode::LBTN) && mbMouseOn)
		{
			mOnClick();
		}

		if (KEY_UP(eKeyCode::LBTN) && mbMouseOn)
		{
			Vector2 pos = GetScreenPos();
			pos = CalculateIndexPos(pos);
			pos -= mParent->GetPos();
			SetPos(pos);
		}
	}
	void UIItem::OnRender(HDC hdc)
	{
		TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			mImage->GetWidth() * 4.0f, mImage->GetHeight() * 3.5f,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));

		HBRUSH oldBrush = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
		HPEN bluePen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);

		Rectangle(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
			(int)mScreenPos.x + mImage->GetWidth() * 4.0f
			, (int)mScreenPos.y + mImage->GetHeight() * 3.5f);

		SelectObject(hdc, oldPen);
		DeleteObject(bluePen);
		SelectObject(hdc, oldBrush);
		
	}
	void UIItem::OnClear()
	{
	}
	void UIItem::Click()
	{
		Vector2 mousePos = Input::GetMousePos();

		//


		// 마우스 드래그 이동
		if (mPrevMousePos.x != 0.0f && mPrevMousePos.y != 0.0f)
		{
			Vector2 pos = GetPos();
			Vector2 distance = mousePos - mPrevMousePos;
			pos.x += distance.x;
			pos.y += distance.y;

			//pos = CalculateIndexPos(pos);
			SetPos(pos);
		}



		mPrevMousePos = mousePos;
	}
	Vector2 UIItem::CalculateIndex(Vector2 pos)
	{
		Vector2 start(399.0f, 51.0f);
		for (size_t y = 0; y < row; y++)
		{
			for (size_t x = 0; x < coulmn; x++)
			{
				Vector2 indexPos;
				indexPos.x = 78 * (x + 1) + 399;
				indexPos.y = 78 * (y + 1) + 51;

				if (indexPos.x < pos.x && indexPos.x + 78.0f > pos.x
					&& indexPos.y < pos.y && indexPos.y + 78.0f > pos.y)
				{
					return Vector2(x, y);
				}
			}
		}

		return Vector2(-1.0f, -1.0f);
	}
	Vector2 UIItem::CalculateIndexPos(Vector2 pos)
	{
		Vector2 start(399.0f, 51.0f);
		for (size_t y = 0; y < row; y++)
		{
			for (size_t x = 0; x < coulmn; x++)
			{
				Vector2 indexPos;
				indexPos.x = 78 * (x)+399;
				indexPos.y = 78 * (y)+51;

				if (indexPos.x < pos.x && indexPos.x + 78.0f > pos.x
					&& indexPos.y < pos.y && indexPos.y + 78.0f > pos.y)
				{
					return Vector2(indexPos);
				}
			}
		}

		return Vector2(-1.0f, -1.0f);
	}
}