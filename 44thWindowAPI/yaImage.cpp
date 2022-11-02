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
			

		return nullptr;
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
}
