#include "yaCollisionManager.h"
#include "yaScene.h"
#include "yaSceneManager.h"
#include "yaGameObject.h"
#include "yaCollider.h"

namespace ya {

    WORD CollisionManager::mMatrix[_COLLIDER_LAYER] = {};
    std::map<UINT64, bool> CollisionManager::mCollisionInformation;


    //std::bitset<_COLLIDER_LAYER> CollisionManager::mMatrix2 = {};

    void CollisionManager::Tick()
    {
        Scene* playeScene = SceneManager::GetPlayScene();

        for (size_t row = 0; row < _COLLIDER_LAYER; row++)
        {
            for (size_t col = 0; col < _COLLIDER_LAYER; col++)
            {
                if (mMatrix[row] & (1 << col))
                {
                    //충돌 이 되었는지 안되었는지를 검사해줘야 한다.
                    LayerCollision(playeScene, (eColliderLayer)row, (eColliderLayer)col);
                }
            }
        }
    }
    void CollisionManager::SetLayer(eColliderLayer left, eColliderLayer right, bool value)
    {
        //더작은 숫자를 행 더큰숫자를 열로
        UINT row = 0;
        UINT col = 0;

        UINT iLeft = (UINT)left;
        UINT iRight = (UINT)right;

        if (iLeft < iRight)
        {
            row = (UINT)left;
            col = (UINT)right;
        }
        else
        {
            row = (UINT)right;
            col = (UINT)left;
        }

        if (value == true)
            mMatrix[row] |= (1 << col);
        else
            mMatrix[row] &= ~(1 << col);

        
    }

    void CollisionManager::LayerCollision(Scene* scene, eColliderLayer left, eColliderLayer right)
    {
        std::vector<GameObject*>& lefts = scene->GetGameObjects(left);
        std::vector<GameObject*>& rights = scene->GetGameObjects(right);

        for (auto leftObject : lefts)
        {
            Collider* leftCollider = leftObject->GetComponent<Collider>();
            if (leftCollider == nullptr)
                continue;

            for (auto rightObject : rights)
            {
                Collider* rightCollider = rightObject->GetComponent<Collider>();

                if (rightCollider == nullptr)
                    continue;

                if (leftObject == rightObject)
                    continue;

                ColliderCollision(leftCollider, rightCollider);
            }
        }
    }
    void CollisionManager::ColliderCollision(Collider* left, Collider* right)
    {
        //두 충돌체의 Layer 번호를 일단 확인해준다
        ColliderID id;
        id.left = left->GetID();
        id.right = right->GetID();

        std::map<UINT64, bool>::iterator iter
            = mCollisionInformation.find(id.ID);

        //충돌정보가 없다면 충돌정보를 생성해준다.
        if (iter == mCollisionInformation.end())
        {
            mCollisionInformation.insert(std::make_pair(id.ID, false));
            iter = mCollisionInformation.find(id.ID);
        }


        if (Intersect(left, right))
        {
            //충돌

            if (iter->second == false)
            {
                //최초 한번 충돌
                

                //충돌함수를 호출해 주면 된다.
                left->OnCollisionEnter(right);
                right->OnCollisionEnter(left);

                iter->second == true;
            }
            else
            {
                //충돌 중일때
                left->OnCollisionStay(right);
                right->OnCollisionStay(left);
            }
            
        }
        else
        {
            //충돌x
            if (iter->second)
            {
                //충돌하고 빠져나올때
                left->OnCollisionExit(right);
                right->OnCollisionExit(left);

                iter->second == false;
            }

            // if (iter->second == false)

        }
    }
    bool CollisionManager::Intersect(Collider* left, Collider* right)
    {
        if (left->GetOwner()->IsDeath())
            return false;
        if (right->GetOwner()->IsDeath())
            return false;

        Vector2 leftPos = left->GetPos();
        Vector2 leftScale = left->GetScale();

        Vector2 rightPos = right->GetPos();
        Vector2 rightScale = right->GetScale();

        if (fabs(leftPos.x  - rightPos.x) < fabs(leftScale.x/2.0f + rightScale.x / 2.0f)
            && fabs(leftPos.y - rightPos.y) < fabs(leftScale.y / 2.0f + rightScale.y / 2.0f))
        {
            return true;
        }

        return false;
    }
}