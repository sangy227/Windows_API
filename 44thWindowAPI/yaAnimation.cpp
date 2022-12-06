#include "yaAnimation.h"
#include "yaImage.h"
#include "yaAniMator.h"
#include "yaGameObject.h"
#include "yaCamera.h"
#include "yaTime.h"

namespace ya {
	Animation::Animation()
		:mAlphaValue(255.0f)
		, mbBlink(false)
	{
	}
	Animation::~Animation()
	{

	}
	void Animation::Tick()
	{
		if (mbComplete)
			return;

		if (mbBlink)
		{
			const float blinkSpeed = 1000.0f;
			

			if (mAlphaValue <= 0.0f)
			{
				mAlphaValue += (blinkSpeed * Time::DeltaTime());
			}
			else
			{
				mAlphaValue -= (blinkSpeed * Time::DeltaTime());
			}
		}
		else
		{
			mAlphaValue = 255.0f;
		}

		mTime += Time::DeltaTime();
		if (mSpriteSheet[mSpriteIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mSpriteSheet.size() <= mSpriteIndex + 1)
				mbComplete = true;
			else
				mSpriteIndex++;
		}
	}
	void Animation::Render(HDC hdc)
	{
		GameObject* gameObj = mAnimator->GetOwner();
		Vector2 pos = gameObj->GetPos();
		Vector2 scale = gameObj->GetScale();

		//여기 카메라 변경
		if (mAffectedCamera
			&& mAnimator->GetMode() != AniMator::Mode::UIGameObject)
			pos = Camera::CalculatePos(pos);


		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = mAlphaValue; // 0 - 225


		pos += mSpriteSheet[mSpriteIndex].offset;

		/*AlphaBlend(hdc
			,int( pos.x - mSpriteSheet[mSpriteIndex].size.x /2.0f)
			,int( pos.y - mSpriteSheet[mSpriteIndex].size.y / 2.0f)
			,int( mSpriteSheet[mSpriteIndex].size.x*5)
			,int( mSpriteSheet[mSpriteIndex].size.y*5)
			,mImage->GetDC()											  
			,int( mSpriteSheet[mSpriteIndex].leftTop.x)
			,int( mSpriteSheet[mSpriteIndex].leftTop.y)
			,int( mSpriteSheet[mSpriteIndex].size.y)
			,int( mSpriteSheet[mSpriteIndex].size.y)
			,func);*/

		TransparentBlt(hdc
			, int(pos.x - mSpriteSheet[mSpriteIndex].size.x )
			, int(pos.y - mSpriteSheet[mSpriteIndex].size.y )
			, int(mSpriteSheet[mSpriteIndex].size.x * (3.5f) )//*scale.x)
			, int(mSpriteSheet[mSpriteIndex].size.y * (3.5f) )//*scale.y)
			, mImage->GetDC()
			, int(mSpriteSheet[mSpriteIndex].leftTop.x)
			, int(mSpriteSheet[mSpriteIndex].leftTop.y)
			, int(mSpriteSheet[mSpriteIndex].size.y)
			, int(mSpriteSheet[mSpriteIndex].size.y)
			, RGB(255, 255, 255));

	}
	void Animation::Create(Image* image, Vector2 leftTop, Vector2 size, Vector2 offset
		, UINT spriteLegth, float duration, bool bAffectedCamera)
	{
		mImage = image;
		mAffectedCamera = bAffectedCamera;


		for (size_t i = 0; i < spriteLegth; i++)
		{
			Sprite sprite;
			sprite.leftTop.x = leftTop.x +(size.x * (float)i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mSpriteSheet.push_back(sprite);
		}
	}
	void Animation::Reset()
	{
		mSpriteIndex = 0;
		mTime = 0.0f;
		mbComplete = false;
	}
}