#include "yaMissile.h"
#include "yaTime.h"

namespace ya {
    Missile::Missile()
        : mSpeed(1.0f)
    {
        SetPos({ 100.0f , 100.0f });
        SetScale({ 50.0f , 50.0f });
    }
    Missile::~Missile()
    {
    }
    void Missile::Tick()
    {
        Vector2 pos = GetPos();

        pos.y -= 500.0f * Time::DeltaTime();

        SetPos(pos);
    }
    void Missile::Render(HDC hdc)
    {
        Vector2 pos = GetPos();
        Vector2 scale = GetScale();
        Ellipse(hdc, pos.x, pos.y, pos.x + scale.x, pos.y + scale.y);

    }
    
}
