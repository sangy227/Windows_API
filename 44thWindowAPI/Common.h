#pragma once

#include "framework.h"

#include <string>
#include <vector>
#include <list>
#include <map>
#include <bitset>

#include "def.h"
#include "Maths.h"

#pragma comment(lib,"Msimg32.lib")

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