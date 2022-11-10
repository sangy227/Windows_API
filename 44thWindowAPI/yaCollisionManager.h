#pragma once
#include"Common.h"

namespace ya {
	class Collider;
	class Scene;
	class CollisionManager
	{
	public:
		static void Tick();
		static void SetLayer(eColliderLayer left, eColliderLayer right,bool value);

		static void LayerCollision(Scene* scene, eColliderLayer left, eColliderLayer right);
		static void ColliderCollision(Collider* left, Collider* right);

		static bool Intersect(Collider* left, Collider* right);

		static void Clear();

	private:
		static WORD mMatrix[_COLLIDER_LAYER];

		static std::bitset<_COLLIDER_LAYER> mMatrix2;

		static std::map<UINT64, bool> mCollisionInformation;
	};
}
