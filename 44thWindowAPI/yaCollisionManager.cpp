#include "yaCollisionManager.h"
#include "yaScene.h"
#include "yaSceneManager.h"
#include "yaGameObject.h"
#include "yaCollider.h"
namespace ya {

    WORD CollisionManager::mMatrix[_COLLIDER_LAYER] = {};

    std::bitset<_COLLIDER_LAYER> CollisionManager::mMatrix2 = {};

    void CollisionManager::Tick()
    {
        Scene* playeScene = SceneManager::GetplayScene();
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


        //if (value == true)
        //    mMatrix2[row] != (1 << col);
      

        
    }

    void CollisionManager::LayerCollision(Scene* scene, eColliderLayer left, eColliderLayer right)
    {
        std::vector<GameObject*>& lefts = scene->GetGameObjects(left);
        std::vector<GameObject*>& rights = scene->GetGameObjects(right);

        for (auto leftObject : lefts)
        {
            if (leftObject->GetComponent<Collider>() == nullptr)
                continue;

            for (auto rightObject : rights)
            {
                if (rightObject->GetComponent<Collider>() == nullptr)
                    continue;

                if (leftObject = rightObject)
                    continue;

                if (Intersect(leftObject->GetComponent<Collider>(), rightObject->GetComponent<Collider>()))
                {
                    //충돌
                }
                else
                {
                    //충돌x
                }
            }
        }
    }
    bool CollisionManager::Intersect(Collider* left, Collider* right)
    {
        Vector2 leftPos = left->GetPos();
        Vector2 leftscale = left->GetScale();

        Vector2 rightPos = right->GetPos();
        Vector2 rightscale = right->GetScale();

        if (fabs(leftPos.x  - rightPos.x) < fabs(leftscale.x/2.0f + rightscale.x / 2.0f)
            && fabs(leftPos.y - rightPos.y) < fabs(leftscale.y / 2.0f + rightscale.y / 2.0f))
        {
            return true;
        }

        return false;
    }
}