#include "yaGround.h"
#include "yaPlayer.h"
#include "yaCollider.h"
#include "yaRigidbody.h"

namespace ya {
    Ground::Ground()
    {
        
        Collider* collider = AddComponent<Collider>();
        collider->SetScale(Vector2(600.0f, 50.0f));
        
    }
    Ground::~Ground()
    {
    }
    void Ground::Tick()
    {
        GameObject::Tick();
    }
    void Ground::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
    void Ground::OnCollisionEnter(Collider* other)
    {
        GameObject* playerObj = other->GetOwner();
        playerObj->GetComponent<Rigidbody>()->SetGround(true);

        float fLen = fabs(other->GetPos().y - GetComponent<Collider>()->GetPos().y);
        //여기 변경 시켜야하는데, 원본 스프라이트를 3.5배 확대시키고 그려서 문제인가
        float fScale = other->GetScale().y / 2.0f + GetComponent<Collider>()->GetScale().y / 2.0f;

        if (fLen < fScale)
        {
            //여기가 플레이어 포스를 움직여주는듯
            Vector2 playerPos = playerObj->GetPos();
            playerPos.y -= (fScale - fLen) - 1.0f;
            playerObj->SetPos(playerPos);
        }
    }
    void Ground::OnCollisionStay(Collider* other)
    {
    }
    void Ground::OnCollisionExit(Collider* other)
    {
    }
}