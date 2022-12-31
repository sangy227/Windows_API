#include "Number_4.h"
#include "yaImage.h"

ya::Number_4::Number_4(eUIType type)
    :UIBase(type)
{
}

ya::Number_4::~Number_4()
{
}

void ya::Number_4::OnInit()
{
}

void ya::Number_4::OnActive()
{
}

void ya::Number_4::OnInActive()
{
}

void ya::Number_4::OnTick()
{
}

void ya::Number_4::OnRender(HDC hdc)
{
    TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
        mImage->GetWidth() * 0.7f, mImage->GetHeight() * 0.7f,
        mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
        , RGB(0, 0, 0));
}

void ya::Number_4::OnClear()
{
}
