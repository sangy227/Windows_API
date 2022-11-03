#pragma once
#include "yaComponent.h"
#include "yaAnimation.h"

namespace ya {
	class Image;
	class AniMator:public Component
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};

		AniMator();
		~AniMator();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		Animation* FindAnimation(const std::wstring& name);

		void CreateAnimation(const std::wstring& name, Image* image,Vector2 leftTop
			,Vector2 size,Vector2 offset,float columnLength,UINT spriteLegth,float duration
			,bool bAffectedCamera = false);

		void Play(std::wstring& name,bool bloop = false);
		
	public:
		Event mStartEvent;
		Event mCompleteEvent;
		Event mEndEvent;

	

	private:
		std::map<const std::wstring&, Animation*> mAnimations;
		Animation* mPlayAnimation;
		bool mLoop;
	};
}

