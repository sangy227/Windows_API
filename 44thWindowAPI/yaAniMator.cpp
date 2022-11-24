#include "yaAniMator.h"
#include "yaGameObject.h"
#include "yaImage.h"
#include "yaCamera.h"
#include "yaResources.h"

namespace ya {
	AniMator::AniMator()
		:Component(eComponentType::Animator)
		,mPlayAnimaion(nullptr)
		,mbLoop(false)
	{
		//mImage = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Player.bmp");
	}




	AniMator::~AniMator()
	{
		//std::map<std::wstring, Events*> mEvents;
		for (auto iter : mAnimations)
		{
			delete iter.second;
		}

		for (auto iter : mEvents)
		{
			delete iter.second;
		}

		//std::map<std::wstring, Animation*> mAnimations;

	}



	void AniMator::Tick()
	{
		if (mPlayAnimaion != nullptr)
		{
			mPlayAnimaion->Tick();

			if (/*mbLoop &&*/ mPlayAnimaion->isComplete())
			{
				AniMator::Events* events = FindEvents(mPlayAnimaion->GetName());
				if (events != nullptr)
					events->mCompleteEvent();
				mPlayAnimaion->Reset();
			}
		}
	}


	void AniMator::Render(HDC hdc)
	{
		if (mPlayAnimaion != nullptr)
		{
			mPlayAnimaion->Render(hdc);
		}

	}




	std::wstring AniMator::CreateAnimationKey(std::wstring path)
	{
		std::wstring keyString = path;

		// 얘니메이션 폴더 이름 추룰
		UINT pos = keyString.find_last_of(L"\\");
		std::wstring tail = keyString.substr(pos + 1, keyString.length());
		keyString = keyString.substr(0, pos);

		// 애니메이션 오브젝트 이름 추출
		pos = keyString.find_last_of(L"\\");
		std::wstring head = keyString.substr(pos + 1, keyString.length());
		keyString = head + tail;

		return keyString;
	}



	Animation* AniMator::FindAnimation(const std::wstring& name)
	{
		std::map<const std::wstring, Animation*>::iterator iter = mAnimations.find(name);
		if (iter == mAnimations.end())
		{
			return nullptr;
		}
		return iter->second;
	}

	void AniMator::CreateAnimation(const std::wstring& name, Image* image
		, Vector2 leftTop, Vector2 size, Vector2 offset
		, UINT spriteLegth, float duration, bool bAffectedCamera)
	{
		Animation* animation = FindAnimation(name);
		if (animation != nullptr)
		{
			MessageBox(nullptr, L"중복 키 애니메이션 생성", L"애니메이션 생성 실패!", MB_OK);
			return;
		}

		
		animation = new Animation();
		animation->Create(image, leftTop, size, offset
			,spriteLegth, duration, bAffectedCamera);

		animation->SetName(name);
		animation->SetAnimator(this);

		mAnimations.insert(std::make_pair(name, animation));

		Events* events = new Events();

		mEvents.insert(std::make_pair(name, events));
	}

	void AniMator::CreateAnimations(const std::wstring& path
		, const std::wstring& name
		, Vector2 offset
		, float duration)
	{
		
		UINT width = 0;
		UINT height = 0;
		UINT fileCount = 0;

		std::filesystem::path fs(path);
		std::vector<Image*> images;
		for (auto& p : std::filesystem::recursive_directory_iterator(path))
		{
			std::wstring fileName = p.path().filename();
			std::wstring keyString = CreateAnimationKey(path);

			std::wstring fullName = path + L"\\" + fileName;

			Image* image = Resources::Load<Image>(keyString, fullName);
			images.push_back(image);

			if (width < image->GetWidth())
				width = image->GetWidth();

			if (height < image->GetHeight())
				height = image->GetHeight();

			fileCount++;
		}
		
		mSPriteSheet = Image::Create(name, width* fileCount, height);
		int index = 0;
		for (Image* image : images)
		{
			BitBlt(mSPriteSheet->GetDC(), width * index, 0, image->GetWidth(), image->GetHeight()
				, image->GetDC(), 0, 0, SRCCOPY);
			index++;
		}
		
		CreateAnimation(name, mSPriteSheet
			, Vector2(0.0f, 0.0f), Vector2(width, height)
			, offset, fileCount, duration);
	}
	
	void AniMator::Play(const std::wstring& name, bool bLoop)
	{
		AniMator::Events* events = FindEvents(name);
		if(events != nullptr)
			events->mStartEvent();

		Animation* prevAnimation = mPlayAnimaion;
		mPlayAnimaion = FindAnimation(name);
		mPlayAnimaion->Reset();
		mbLoop = bLoop;

		if (prevAnimation != mPlayAnimaion) 
		{
			if (events != nullptr)
				events->mEndEvent();
		}
	}
	AniMator::Events* AniMator::FindEvents(const std::wstring key)
	{
		std::map<std::wstring, Events*>::iterator iter = mEvents.find(key);
		if (iter == mEvents.end())
		{
			return nullptr;
		}

		return iter->second;
		
	}

	std::function<void()>& AniMator::GetStartEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->mStartEvent.mEvent;
	}

	std::function<void()>& AniMator::GetCompleteEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->mCompleteEvent.mEvent;
	}

	std::function<void()>& AniMator::GetEndEvent(const std::wstring key)
	{
		Events* events = FindEvents(key);

		return events->mEndEvent.mEvent;
	}

}