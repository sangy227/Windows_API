#include "Number_8.h"
#include "yaImage.h"

ya::Number_8::Number_8(eUIType type)
    :UIBase(type)
{
}

ya::Number_8::~Number_8()
{
}

void ya::Number_8::OnInit()
{
}

void ya::Number_8::OnActive()
{
}

void ya::Number_8::OnInActive()
{
}

void ya::Number_8::OnTick()
{
}

void ya::Number_8::OnRender(HDC hdc)
{
    TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
        mImage->GetWidth() * 0.7f, mImage->GetHeight() * 0.7f,
        mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
        , RGB(0, 0, 0));
}

void ya::Number_8::OnClear()
{
}
