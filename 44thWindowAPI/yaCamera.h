#pragma once
#include "Common.h"
namespace ya {
	class GameObject;
	class Camera
	{
	public:
		static void Initialize();
		static void Tick();

		static Vector2 CalculatePos(Vector2 pos) { return pos - mDistance; }
		static void SetTarget(GameObject* target) { mTarget = target; }

	private:
		Camera()=default;
		~Camera()=default;

	private:
		static Vector2 mResolution; // 화면 해상도
		static Vector2 mLookPosition;
		static Vector2 mDistance;
		static GameObject* mTarget;
	};
}

