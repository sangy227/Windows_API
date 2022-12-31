#include "yaPanel.h"
#include "yaImage.h"

namespace ya {
    Panel::Panel(eUIType type)
        :UIBase(type)
    {

    }
    Panel::~Panel()
    {

    }
    void Panel::OnInit()
    {

    }
    void Panel::OnActive()
    {

    }
    void Panel::OnInActive()
    {

    }
    void Panel::OnTick()
    {

    }
    void Panel::OnRender(HDC hdc)
    {
       /* BLENDFUNCTION func = {};
        func.BlendOp = AC_SRC_OVER;
        func.BlendFlags = 0;
        func.AlphaFormat = AC_SRC_ALPHA;
        func.SourceConstantAlpha = 255;

        AlphaBlend(hdc, (int)mScreenPos.x, (int)mScreenPos.y
            , mImage->GetWidth()*5, mImage->GetHeight()*5
            , mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight(), func);*/

        TransparentBlt(hdc, (int)mScreenPos.x, (int)mScreenPos.y, 
            mImage->GetWidth(), mImage->GetHeight(),
            mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
            , RGB(255, 255, 255));
    }
    void Panel::OnClear()
    {

    }
    
}