#include "Number_1.h"
#include "yaImage.h"

ya::Number_1::Number_1(eUIType type)
    :UIBase(type)
{
}

ya::Number_1::~Number_1()
{
}

void ya::Number_1::OnInit()
{
}

void ya::Number_1::OnActive()
{
}

void ya::Number_1::OnInActive()
{
}

void ya::Number_1::OnTick()
{
}

void ya::Number_1::OnRender(HDC hdc)
{
    TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
        mImage->GetWidth() * 0.7f, mImage->GetHeight() * 0.7f,
        mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
        , RGB(0, 0, 0));
}

void ya::Number_1::OnClear()
{
}
