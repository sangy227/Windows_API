#include "Number_9.h"
#include "yaImage.h"

ya::Number_9::Number_9(eUIType type)
    :UIBase(type)
{
}

ya::Number_9::~Number_9()
{
}

void ya::Number_9::OnInit()
{
}

void ya::Number_9::OnActive()
{
}

void ya::Number_9::OnInActive()
{
}

void ya::Number_9::OnTick()
{
}

void ya::Number_9::OnRender(HDC hdc)
{
    TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
        mImage->GetWidth() * 0.7f, mImage->GetHeight() * 0.7f,
        mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
        , RGB(0, 0, 0));
}

void ya::Number_9::OnClear()
{
}
