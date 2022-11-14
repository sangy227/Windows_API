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
		struct Events
		{
			Event mStartEvent;
			Event mCompleteEvent;
			Event mEndEvent;

		};

		AniMator();
		~AniMator();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;


		std::wstring CreateAnimationKey(std::wstring path);
		Animation* FindAnimation(const std::wstring& name);

		void CreateAnimation(const std::wstring& name, Image* image,
			Vector2 leftTop,Vector2 size,Vector2 offset
			,UINT spriteLegth,float duration,bool bAffectedCamera = false);

		void CreateAnimations(const std::wstring& path, const std::wstring& name, 
			Vector2 offset=Vector2::Zero, float duration=0.1f);

		void Play(const std::wstring& name,bool bLoop = false);

		Events* FindEvents(const std::wstring key);
		std::function<void()>& GetStartEvent(const std::wstring key);
		std::function<void()>& GetCompleteEvent(const std::wstring key);
		std::function<void()>& GetEndEvent(const std::wstring key);
		
		
	public:
		Event mStartEvent;
		Event mCompleteEvent;
		Event mEndEvent;

	private:
		std::map<std::wstring, Events*> mEvents;
		std::map<std::wstring, Animation*> mAnimations;


		Animation* mPlayAnimaion;
		bool mbLoop;
		Image* mSPriteSheet;
	};
}

