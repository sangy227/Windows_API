#include "Map_Gate.h"
#include "yaImage.h"
ya::Map_Gate::Map_Gate(eUIType type)
    :UIBase(type)
{

}

ya::Map_Gate::~Map_Gate()
{
}

void ya::Map_Gate::OnInit()
{
}

void ya::Map_Gate::OnActive()
{
}

void ya::Map_Gate::OnInActive()
{
}

void ya::Map_Gate::OnTick()
{
}

void ya::Map_Gate::OnRender(HDC hdc)
{
    TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y,
        mImage->GetWidth() * 1.2f, mImage->GetHeight() * 1.2f,
        mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
        , RGB(255, 255, 255));
}

void ya::Map_Gate::OnClear()
{
}
