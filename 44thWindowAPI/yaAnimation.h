#pragma once
#include "Common.h"
#include "yaEntity.h"

namespace ya {
	class Image;
	class AniMator;
	class Animation : public Entity
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				:leftTop(0.0f, 0.0f)
				, size(0.0f, 0.0f)
				, offset(0.0f, 0.0f)
				, duration(0.0f)
			{

			}
		};

		Animation();
		~Animation();

		void Tick();
		void Render(HDC hdc);
		
		void Create(Image* image
			, Vector2 leftTop,Vector2 size, Vector2 offset
			,UINT spriteLegth, float duration, bool bAffectedCamera = true);

		void Reset();
		bool isComplete() { return mbComplete; }
		void SetAnimator(AniMator* animator) { mAnimator = animator; }

	private:
		AniMator* mAnimator;
		Image* mImage;
		std::vector<Sprite> mSpriteSheet;
		UINT mSpriteIndex;
		float mTime;

		bool mStart;
		bool mbComplete;
		bool mEnd;
		bool mAffectedCamera;
	};
}

