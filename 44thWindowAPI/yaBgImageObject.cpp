#include "yaBgImageObject.h"
#include "yaResources.h"
#include "yaImage.h"
namespace ya {
	BgImageObject::BgImageObject()
		: mImage(nullptr)
	{
		SetPos(Vector2::Zero);
		SetScale(Vector2::One);
	}
	BgImageObject::~BgImageObject()
	{
	}
	void BgImageObject::Initialize()
	{
		Vector2 pos = GetPos();
		pos.x += 900.0f;
		SetPos(pos);
	}
	void BgImageObject::Tick()
	{
		if (mBgStatus == BgStatus::MOVE) {
			Vector2 pos = GetPos();
			pos.x -= 2.0f;
			SetPos(pos);
		}

		GameObject::Tick();
	}
	void BgImageObject::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();
		
		Vector2 finalPos = pos;

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x*5;
		rect.y = mImage->GetHeight() * scale.y*5;

		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));

		GameObject::Render(hdc);
	}
	void BgImageObject::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\Image\\Object\\";
		path += fileName;

		mImage = Resources::Load<Image>(key, path);
	}
}