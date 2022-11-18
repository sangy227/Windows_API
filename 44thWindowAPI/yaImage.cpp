#include "yaImage.h"
#include "yaApplication.h"
#include "yaResources.h"

namespace ya {
	Image* Image::Create(const std::wstring& key, UINT width, UINT heihgt)
	{
		Image* image = Resources::Find<Image>(key);
		if (image != nullptr)
		{
			MessageBox(nullptr, L"중복 키 이미지 생성", L"이미지 생성 실패!", MB_OK);
			return nullptr;
		}

		//이미지를 생성해줘야한다.
		image = new Image();
		HDC mainHdc = Application::GetInstance().GetHdc();

		image->mBitmap = CreateCompatibleBitmap(mainHdc, width, heihgt);
		image->mHdc = CreateCompatibleDC(mainHdc);

		if (image->mBitmap == NULL
			|| image->mHdc == NULL)
		{
			return nullptr;
		}

		HBITMAP defaultBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
		DeleteObject(defaultBitmap);

		//비트맵 정보 확인
		BITMAP bitmap = {};
		GetObject(image->mBitmap, sizeof(BITMAP), &bitmap);
			
		image->mWidth = bitmap.bmWidth;
		image->mHeight = bitmap.bmHeight;

		image->SetKey(key);

		Resources::Insert<Image>(key, image);
		return image;
	}
	Image::Image()
		: mBitmap(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
	{

	}
	Image::~Image()
	{
		HWND hWnd = Application::GetInstance().GetWindowData().hWnd;
		ReleaseDC(hWnd, mHdc);
	}


	HRESULT Image::Load(const std::wstring& path)
	{
		mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), 
			IMAGE_BITMAP, 0, 0,
			LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		if (mBitmap == nullptr)
		{
			return E_FAIL;
		}

		BITMAP bitInfo = {};
		GetObject(mBitmap, sizeof(BITMAP), &bitInfo);

		mWidth = bitInfo.bmWidth;
		mHeight = bitInfo.bmHeight;

		HDC mainDC = Application::GetInstance().GetWindowData().hdc;
		mHdc = CreateCompatibleDC(mainDC);

		HBITMAP prevBit = (HBITMAP)SelectObject(mHdc, mBitmap);
		DeleteObject(prevBit);

		return S_OK;
	}
	Pixel Image::GetPixel(int x, int y)
	{
		y = mHeight - (y + 1);

		Pixel* pixel = (Pixel*)mBitmap;
		pixel += (mWidth * y + x);

		return *pixel;
	}
	void Image::SetPixel(int x, int y, Pixel pixel)
	{
		// 비트맵 좌표는 촤측하단이 0,0 
		// 윈도우좌표처럼 사용하려면 y를 반대로 바꾸어 주어야 한다.
		y = mHeight - (y + 1);

		Pixel* bitmapPixel = (Pixel*)mBitmap;
		bitmapPixel += (mWidth * y + x);

		*bitmapPixel = pixel;
	}
}
