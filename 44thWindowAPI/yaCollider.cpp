#include "yaCollider.h"
#include "yaGameObject.h"
#include "yaApplication.h"
#include "yaCamera.h"


namespace ya {
	Collider::Collider()
		: Component(eComponentType::Animator)
		, mOffset(Vector2::Zero)
		//, mPos(Vector2::Zero)
		, mScale(Vector2::One)
		, mCollisionCount(0)

	{
		mScale = Vector2(168.0f, 168.0f);
		
	}
	Collider::~Collider()
	{

	}
	void Collider::Tick()
	{
		GameObject* owner = GetOwner();
		
		mPos = owner->GetPos() + mOffset;
	}
	void Collider::Render(HDC hdc)
	{
		

		HBRUSH tr = Application::GetInstance().GetBrush(eBrushColor::Transparent);
		Brush brush(hdc, tr);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = NULL;

		
		if (mCollisionCount > 0)
			oldPen = (HPEN)SelectObject(hdc, redPen);
		else
			oldPen = (HPEN)SelectObject(hdc, greenPen);

		mPos = Camera::CalculatePos(GetPos());

		Rectangle(hdc, (mPos.x - mScale.x / 2.0f), (mPos.y - mScale.y / 2.0f)
			, (mPos.x + mScale.x / 2.0f), (mPos.y + mScale.y / 2.0f));

		SelectObject(hdc, oldPen);
		DeleteObject(redPen);
		DeleteObject(greenPen);
	}
	void Collider::OnCollisionEnter(Collider* other)
	{
		mCollisionCount++;
		GetOwner()->OnCollisionEnter(other);
	}
	void Collider::OnCollisionStay(Collider* other)
	{
		GetOwner()->OnCollisionEnter(other);

	}
	void Collider::OnCollisionExit(Collider* other)
	{
		mCollisionCount--;
		GetOwner()->OnCollisionEnter(other);

	}
}