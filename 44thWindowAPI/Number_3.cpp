#include "Number_3.h"
#include "yaImage.h"

ya::Number_3::Number_3(eUIType type)
    :UIBase(type)
{
}

ya::Number_3::~Number_3()
{
}

void ya::Number_3::OnInit()
{
}

void ya::Number_3::OnActive()
{
}

void ya::Number_3::OnInActive()
{
}

void ya::Number_3::OnTick()
{
}

void ya::Number_3::OnRender(HDC hdc)
{
    TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
        mImage->GetWidth() * 0.7f, mImage->GetHeight() * 0.7f,
        mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
        , RGB(0, 0, 0));
}

void ya::Number_3::OnClear()
{
}
