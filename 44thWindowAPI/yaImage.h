#pragma once
#include "yaResource.h"
namespace ya 
{
	class Image : public Resource
	{
	public:
		static Image* Create(const std::wstring& key, UINT width, UINT heihgt);

		Image();
		~Image();

		virtual HRESULT Load(const std::wstring& path) override;


		HDC GetDC() { return mHdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }


		Pixel GetPixel(int x, int y);
		void SetPixel(int x, int y, Pixel pixel);
	private:
		HBITMAP mBitmap;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;
	};
}

