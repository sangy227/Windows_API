#include "yaMissile.h"
#include "yaTime.h"
#include "yaCollider.h"
#include "yaCamera.h"
#include "yaAniMator.h"
#include "yaResources.h"
#include "yaImage.h"

namespace ya {
    Missile::Missile()
        : mSpeed(1.0f)
        , mAliveTime(5.0f)
    {
        SetPos({ 100.0f , 100.0f });
        SetScale({ 20.0f , 20.0f });

        Collider* col = new Collider();
        col->SetScale(Vector2(168.0f, 168.0f));

        AddComponent(col);

        if (mImage == nullptr)
        {
            mImage = Resources::Load<Image>(L"Missile", L"..\\Resources\\Image\\attack.bmp");
        }

        AniMator* ani = new AniMator();
        ani->CreateAnimation(L"Idle", mImage
            , Vector2(0.0f, 0.0f), Vector2(64.0f, 48.0f)
            , Vector2(-36.0f, -48.0f), 4, 0.1f);

        ani->Play(L"Idle", true);

        AddComponent(ani);

        //Camera::SetTarget(this);

    }
    Missile::~Missile()
    {
    }

    void Missile::Tick()
    {
        GameObject::Tick();
        mAliveTime -= Time::DeltaTime();
        if (mAliveTime <=0.0f)
        {
            this->Death();
        }




        float radian = DegreeToRadian(90.0f);
        float degree = RadianToDegree(2 * PI);
        float speed = 100.0f;

        Vector2 pos = GetPos();
        // 삼각함수를 이용한 회전
        //mDir = PI / 2.0f;
        //pos.x += speed * cosf(mDir) * Time::DeltaTime();
        //pos.y -= speed * sinf(mDir) * Time::DeltaTime();

        // 벡터를 이용한 회전
        pos.y += mDir.y * speed * Time::DeltaTime();
        pos.x += mDir.x * speed * Time::DeltaTime();

 
        //pos.x += 500.0f * Time::DeltaTime();


        SetPos(pos);
    }
    void Missile::Render(HDC hdc)
    {
        /*Vector2 pos = GetPos();
        Vector2 scale = GetScale();

        pos = Camera::CalculatePos(pos);

        Ellipse(hdc, pos.x-10, pos.y-10, pos.x + scale.x, pos.y + scale.y);*/

        
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
