#include "Ending_Cheese.h"
#include "yaImage.h"
ya::Ending_Cheese::Ending_Cheese(eUIType type)
    :UIBase(type)
{
}

ya::Ending_Cheese::~Ending_Cheese()
{
}

void ya::Ending_Cheese::OnInit()
{
}

void ya::Ending_Cheese::OnActive()
{
}

void ya::Ending_Cheese::OnInActive()
{
}

void ya::Ending_Cheese::OnTick()
{
}

void ya::Ending_Cheese::OnRender(HDC hdc)
{
    TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
        mImage->GetWidth()*3, mImage->GetHeight() * 3,
        mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
        , RGB(255, 255, 255));
}

void ya::Ending_Cheese::OnClear()
{
}
