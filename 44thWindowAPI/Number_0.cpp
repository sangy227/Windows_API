#include "Number_0.h"
#include "yaImage.h"

ya::Number_0::Number_0(eUIType type)
    :UIBase(type)
{
}

ya::Number_0::~Number_0()
{
}

void ya::Number_0::OnInit()
{
}

void ya::Number_0::OnActive()
{
}

void ya::Number_0::OnInActive()
{
}

void ya::Number_0::OnTick()
{
}

void ya::Number_0::OnRender(HDC hdc)
{
    TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
        mImage->GetWidth()*0.7f, mImage->GetHeight()*0.7f,
        mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
        , RGB(0, 0, 0));
}

void ya::Number_0::OnClear()
{
}
