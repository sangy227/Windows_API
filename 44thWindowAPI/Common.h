#pragma once

#include "framework.h"

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <bitset>
#include <functional>
#include <filesystem>
#include <assert.h>
#include <math.h>
#include <set>	
#include "def.h"
#include "Maths.h"

//내가 추가


//그리는 라이브러리
#pragma comment(lib,"Msimg32.lib")

//사운드 헤더파일 추가
#include <mmsystem.h>
#include <dsound.h>
#include <dinput.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dsound.lib")

struct Pixel
{
	BYTE R;
	BYTE G;
	BYTE B;
	BYTE A;

	Pixel(BYTE r, BYTE g, BYTE b, BYTE a)
		: R(r), G(g), B(b), A(a)
	{

	}
};

struct WindowData
{
	HWND hWnd;
	HDC hdc;
	HBITMAP backTexture;
	HDC backBuffer;
	UINT height;
	UINT width;

	void clear()
	{
		hWnd = nullptr;
		hdc = nullptr;
		height = 0;
		width = 0;
	}
};

struct Pen
{
private:
	HDC mHdc;
	HPEN mOldPen;
	HPEN mPen;

public:
	Pen(HDC hdc)
		: mHdc(hdc)
		, mOldPen(NULL)
		, mPen(NULL)
	{

	}

	Pen(HDC hdc, HPEN pen)
		: mHdc(hdc)
		, mOldPen(NULL)
		, mPen(pen)
	{
		mOldPen = (HPEN)SelectObject(mHdc, pen);
	}

	~Pen()
	{
		SelectObject(mHdc, mOldPen);
		DeleteObject(mPen);
	}
	void SetPen(HPEN pen)
	{
		mOldPen = (HPEN)SelectObject(mHdc, pen);
	}
	
};

struct Brush
{
private:
	HDC mHdc;
	HBRUSH mOldBrush;
	HBRUSH mBrush;

public:
	Brush(HDC hdc, HBRUSH brush)
		: mHdc(hdc)
		, mBrush(brush)
		, mOldBrush(NULL)

	{
		mOldBrush = (HBRUSH)SelectObject(mHdc, brush);
	}

	

	~Brush()
	{
		SelectObject(mHdc, mOldBrush);
		DeleteObject(mBrush);
	}
};