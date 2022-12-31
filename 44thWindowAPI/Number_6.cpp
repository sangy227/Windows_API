#include "Number_6.h"
#include "yaImage.h"

ya::Number_6::Number_6(eUIType type)
    :UIBase(type)
{
}

ya::Number_6::~Number_6()
{
}

void ya::Number_6::OnInit()
{
}

void ya::Number_6::OnActive()
{
}

void ya::Number_6::OnInActive()
{
}

void ya::Number_6::OnTick()
{
}

void ya::Number_6::OnRender(HDC hdc)
{
    TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
        mImage->GetWidth() * 0.7f, mImage->GetHeight() * 0.7f,
        mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
        , RGB(0, 0, 0));
}

void ya::Number_6::OnClear()
{
}
