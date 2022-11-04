#include "yaAniMator.h"
#include "yaGameObject.h"
#include "yaImage.h"
#include "yaCamera.h"
#include "yaResources.h"

namespace ya {
	AniMator::AniMator()
		:Component(eComponentType::Aimator)
		,mPlayAnimaion(nullptr)
		,mbLoop(false)
	{
		//mImage = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Player.bmp");
	}
	AniMator::~AniMator()
	{

	}
	void AniMator::Tick()
	{
		if (mPlayAnimaion != nullptr)
		{
			mPlayAnimaion->Tick();

			if (mbLoop && mPlayAnimaion->isComplete())
			{
				mCompleteEvent();
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
	}
	
	void AniMator::Play(const std::wstring& name, bool bloop)
	{
		mStartEvent();

		Animation* prevAnimation = mPlayAnimaion;
		mPlayAnimaion = FindAnimation(name);
		mPlayAnimaion->Reset();
		mbLoop = bloop;

		if (prevAnimation != mPlayAnimaion)
			mEndEvent();
	}
}