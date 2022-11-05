#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Logo : public GameObject
	{
	public:
		Logo();
		~Logo();

		virtual void Initialize() override;
		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetImage(const std::wstring& key, const std::wstring& fileName);

	private:
		Image* mImage;
	};
}