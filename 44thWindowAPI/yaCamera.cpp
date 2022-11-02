#include "yaCamera.h"
#include "yaApplication.h"
#include "yaGameObject.h"
#include "yaInput.h"
#include "yaTime.h"
#include "yaImage.h"

namespace ya {
	Vector2 Camera::mResolution = Vector2::Zero;// 화면 해상도
	 Vector2 Camera::mLookPosition = Vector2::Zero;;
	 Vector2 Camera::mDistance = Vector2::Zero;;
	 GameObject* Camera::mTarget = nullptr;

	  eCameraEffect Camera::mEffect = eCameraEffect::None;
	  Image* Camera::mCutton=nullptr; // 검정색 이미지
	  float Camera::mAlphaTime=0.0f;

	  float Camera::mCuttonAlpha=1.0f;
	  float Camera::mEndTime=5.0f;

	void Camera::Initialize()
	{
		WindowData data = Application::GetInstance().GetWindowData();

		mResolution = Vector2(data.width, data.height);

		mLookPosition = mResolution / 2.0f;

		mEffect = eCameraEffect::FadeIn;
		mCutton = Image::Create(L"CamereCutton", 600, 500);
		
		
	}
	void Camera::Tick()
	{
		if (KEY_PREESE(eKeyCode::UP))
		{
			mLookPosition.y -= 600.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::DOWN))
		{
			mLookPosition.y += 600.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::LEFT))
		{
			mLookPosition.x -= 600.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::RIGHT))
		{
			mLookPosition.x += 600.0f * Time::DeltaTime();
		}


		if (mTarget != nullptr)
		{
			mLookPosition = mTarget->GetPos();
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
	void Camera::Render(HDC hdc)
	{
	}
}
