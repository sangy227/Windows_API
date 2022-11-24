#pragma once
#include "Common.h"
namespace ya {
	class Image;
	class GameObject;
	class Camera
	{
	public:
		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);

		static Vector2 CalculatePos(Vector2 pos) 
		{ 
			//pos.x - mDistance.x;
			return pos - mDistance; // pos;
		}
		static void SetTarget(GameObject* target) { mTarget = target; }

		static void SetCameraEffect(eCameraEffect effect) { mEffect = effect; }
	private:
		Camera()=default;
		~Camera()=default;

	private:
		static Vector2 mResolution; // 화면 해상도
		static Vector2 mLookPosition;
		static Vector2 mDistance; // 해상도 중심좌표와 현재 카메라의 간격
		static GameObject* mTarget;


		static eCameraEffect mEffect;
		static Image* mCutton; // 검정색 이미지
		static float mAlphaTime;

		static float mCuttonAlpha;
		static float mEndTime;
	};
}

