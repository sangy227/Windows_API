#include "Number_7.h"
#include "yaImage.h"

ya::Number_7::Number_7(eUIType type)
    :UIBase(type)
{
}

ya::Number_7::~Number_7()
{
}

void ya::Number_7::OnInit()
{
}

void ya::Number_7::OnActive()
{
}

void ya::Number_7::OnInActive()
{
}

void ya::Number_7::OnTick()
{
}

void ya::Number_7::OnRender(HDC hdc)
{
    TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
        mImage->GetWidth() * 0.7f, mImage->GetHeight() * 0.7f,
        mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
        , RGB(0, 0, 0));
}

void ya::Number_7::OnClear()
{
}
