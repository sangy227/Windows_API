#pragma once

#include "Common.h"
#include "yaEntity.h"
#include "yaComponent.h"

namespace ya {
	class Collider;
	class GameObject : public Entity
	{
	public:
		GameObject();
		GameObject(Vector2 position);

		virtual ~GameObject();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }
		void SetScale(Vector2 scale) { mScale = scale; }
		Vector2 GetScale() { return mScale; }

		void Death() { mDead = true; }
		bool IsDeath() { return mDead; }
		void SetDeathTime(float time) {
			if (mDeathTime <= 0.0f)
			{
				mDeathTime = time , mDeathTimeOn = true; 
			}
		}

		/*void SetHdc(HDC hdc) { mHdc = hdc; }
		HDC GetHdc() {
			return mHdc;
		}*/

		void AddComponent(Component* component);
		template<typename T>
		__forceinline T* AddComponent()
		{
			T* comp = new T();
			GameObject::AddComponent(comp);

			return comp;
		}


		template<typename T>
		__forceinline T* GetComponent()
		{
			T* component;
			for (Component* c : mComponents)
			{
				component = dynamic_cast<T*>(c);

				if (component != nullptr)
					return component;
				
			}

			return nullptr;
		}

		void DeathLoop();

	private:
		std::vector<Component*> mComponents;
		Vector2 mPos;
		Vector2 mScale;
		//HDC mHdc;
		bool mDead;
		float mDeathTime;
		bool mDeathTimeOn;

		
	};
}

