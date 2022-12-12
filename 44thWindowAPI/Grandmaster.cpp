#include "Grandmaster.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaImage.h"

namespace ya {
    Grandmaster::Grandmaster()
    {
        SetName(L"Grandmaster");
        SetPos({ 1070.0f, 770.0f });
        SetScale({ 3.0f, 3.0f });

        if (mImage == nullptr)
        {
            mImage = Resources::Load<Image>(L"Grandmaster", L"..\\Resources\\Image\\Monster\\Grandmaster.bmp");
        }

        mAnimator = new AniMator();
        mAnimator->CreateAnimation(L"Idle", mImage
            , Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
            , Vector2(-24.0f, -48.0f), 4, 0.4f);

        mAnimator->Play(L"Idle", true);

        AddComponent(mAnimator);
        AddComponent(new Collider());
    }
    Grandmaster::Grandmaster(Vector2 position)
    {
        SetName(L"Grandmaster");
        SetPos(position);
        SetScale({ 3.0f, 3.0f });

        if (mImage == nullptr)
        {
            mImage = Resources::Load<Image>(L"Grandmaster", L"..\\Resources\\Image\\Monster\\Grandmaster.bmp");
        }

        mAnimator = new AniMator();
        mAnimator->CreateAnimation(L"Idle", mImage
            , Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
            , Vector2(-24.0f, -48.0f), 4, 0.4f);

        mAnimator->Play(L"Idle", true);

        AddComponent(mAnimator);
        AddComponent(new Collider());
    }
    Grandmaster::~Grandmaster()
    {
    }
    void Grandmaster::Tick()
    {
        GameObject::Tick();

        Vector2 pos = GetPos();

        SetPos(pos);
    }
    void Grandmaster::Render(HDC hdc)
    {
        GameObject::Render(hdc);
    }
    void Grandmaster::OnCollisionEnter(Collider* other)
    {
    }
    void Grandmaster::OnCollisionStay(Collider* other)
    {
    }
    void Grandmaster::OnCollisionExit(Collider* other)
    {
    }
}