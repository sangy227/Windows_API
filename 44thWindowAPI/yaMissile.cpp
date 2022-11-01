#include "yaMissile.h"
#include "yaTime.h"
#include "yaCollider.h"
#include "yaCamera.h"


namespace ya {
    Missile::Missile()
        : mSpeed(1.0f)
    {
        SetPos({ 100.0f , 100.0f });
        SetScale({ 20.0f , 20.0f });

        Collider* col = new Collider();
        col->SetScale(Vector2(20.0f, 20.0f));

        AddComponent(col);
        Camera::SetTarget(this);

    }
    Missile::~Missile()
    {
    }
    void Missile::Tick()
    {
        GameObject::Tick();

        Vector2 pos = GetPos();

        pos.y -= 500.0f * Time::DeltaTime();

        SetPos(pos);


    }
    void Missile::Render(HDC hdc)
    {
        Vector2 pos = GetPos();
        Vector2 scale = GetScale();

        pos = Camera::CalculatePos(pos);

        Ellipse(hdc, pos.x-10, pos.y-10, pos.x + scale.x, pos.y + scale.y);

        //Ãß°¡
        GameObject::Render(hdc);


    }

    void Missile::OnCollisionEnter(Collider* other)
    {
        GameObject* gameObj = other->GetOwner();
        gameObj->Death();

        this->Death();
        
    }

    void Missile::OnCollisionStay(Collider* other)
    {
    }

    void Missile::OnCollisionExit(Collider* other)
    {
    }
    
}
