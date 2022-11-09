#include "Logo.h"
#include "yaResources.h"
#include "yaImage.h"

namespace ya {
	Logo::Logo()
		: mImage(nullptr)
	{
		SetPos({ 345.0f,50.0f });
		SetScale(Vector2::One);
	}
	Logo::~Logo()
	{
	}
	void Logo::Initialize()
	{
	}
	void Logo::Tick()
	{
		GameObject::Tick();

	}
	void Logo::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		Vector2 finalPos = pos;

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x ;
		rect.y = mImage->GetHeight() * scale.y ;

		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));

		GameObject::Render(hdc);
	}
	void Logo::SetImage(const std::wstring& key, const std::wstring& fileName)
	{
		std::wstring path = L"..\\Resources\\Image\\Object\\";
		path += fileName;

		mImage = Resources::Load<Image>(key, path);
	}
}