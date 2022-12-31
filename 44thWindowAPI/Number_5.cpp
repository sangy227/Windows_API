#include "Number_5.h"
#include "yaImage.h"

ya::Number_5::Number_5(eUIType type)
    :UIBase(type)
{
}

ya::Number_5::~Number_5()
{
}

void ya::Number_5::OnInit()
{
}

void ya::Number_5::OnActive()
{
}

void ya::Number_5::OnInActive()
{
}

void ya::Number_5::OnTick()
{
}

void ya::Number_5::OnRender(HDC hdc)
{
    TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
        mImage->GetWidth() * 0.7f, mImage->GetHeight() * 0.7f,
        mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
        , RGB(0, 0, 0));
}

void ya::Number_5::OnClear()
{
}
