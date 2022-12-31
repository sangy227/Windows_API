#include "Number_2.h"
#include "yaImage.h"

ya::Number_2::Number_2(eUIType type)
    :UIBase(type)
{
}

ya::Number_2::~Number_2()
{
}

void ya::Number_2::OnInit()
{
}

void ya::Number_2::OnActive()
{
}

void ya::Number_2::OnInActive()
{
}

void ya::Number_2::OnTick()
{
}

void ya::Number_2::OnRender(HDC hdc)
{
    TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
        mImage->GetWidth() * 0.7f, mImage->GetHeight() * 0.7f,
        mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
        , RGB(0, 0, 0));
}

void ya::Number_2::OnClear()
{
}
