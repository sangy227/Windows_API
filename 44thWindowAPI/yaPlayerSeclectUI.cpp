#include "yaPlayerSeclectUI.h"
#include "yaTime.h"
#include "yaCollider.h"
#include "yaCamera.h"
#include "yaResources.h"
#include "yaImage.h"

namespace ya {
	PlayerSeclectUI::PlayerSeclectUI()
	{
		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"SelectUI", L"..\\Resources\\Image\\SelectUI.bmp");
		}

		SetPos({ 1600 / 2,420 });
		SetScale({ 1.0f, 1.0f });
	}
	PlayerSeclectUI::~PlayerSeclectUI()
	{

	}
	void PlayerSeclectUI::Tick()
	{
		GameObject::Tick();
	}
	void PlayerSeclectUI::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		Vector2 finalPos;
		finalPos.x = (pos.x - mImage->GetWidth() * (scale.x / 2.0f));
		finalPos.y = (pos.y - mImage->GetHeight() * (scale.y / 2.0f));

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;

		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y,
			mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(0, 0, 0));

		GameObject::Render(hdc);
	}
	void PlayerSeclectUI::OnCollisionEnter(Collider* other)
	{
	}
	void PlayerSeclectUI::OnCollisionStay(Collider* other)
	{
	}
	void PlayerSeclectUI::OnCollisionExit(Collider* other)
	{
	}
}