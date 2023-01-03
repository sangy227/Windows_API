#include "yaMonster.h"

#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaMissile.h"
#include "yaScene.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaAniMator.h"
#include "yaCollider.h"
#include "yaCamera.h"
#include "yaAniMator.h"
#include "yaUIManager.h"
namespace ya {
	Monster::Monster()
		: mTime(0.0f)
		, mHP(5)
	{
		SetName(L"Monster");
		SetPos({ 1070.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"crow_bandit", L"..\\Resources\\Image\\Monster\\crow_bandit.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());

		

	}
	Monster::Monster(Vector2 position)
		: mTime(0.0f)
		, mHP(5)
	{
		SetName(L"Monster");
		SetPos(position);
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"bearded_dragon", L"..\\Resources\\Image\\Monster\\bearded dragon.bmp");
		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.4f);

		mAnimator->Play(L"Idle", true);

		AddComponent(mAnimator);
		AddComponent(new Collider());
	}

	Monster::~Monster()
	{
	}

	void Monster::Tick()
	{
		GameObject::Tick();

		Vector2 pos = GetPos();

		SetPos(pos);

		Vector2 mousePos = Input::GetMousePos();
		Vector2 size = GetSize();

		//??
		/*if (mScreenPos.x <= mousePos.x && mousePos.x < mScreenPos.x + size.x *3.5f
			&& mScreenPos.y <= mousePos.y && mousePos.y < mScreenPos.y + size.y*3.5f)
		{
			if (KEY_DOWN(eKeyCode::LBTN))
			{
				int a = 0;
			}
		}*/
		

		

		/*mTime += Time::DeltaTime();

		if (mTime > 5.0f)
		{
			pos.x -= 30;
			SetPos(pos);
			mTime = 0.0f;
		}*/
	}
	void Monster::Render(HDC hdc)
	{
	/*	Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		Vector2 finalPos;
		finalPos.x = (pos.x - mImage->GetWidth() * (scale.x / 2.0f));
		finalPos.y = (pos.y - mImage->GetHeight() * (scale.y / 2.0f));

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;

		finalPos = Camera::CalculatePos(finalPos);


		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 255, 255));*/

		GameObject::Render(hdc);
	}
	void Monster::OnCollisionEnter(Collider* other)
	{

	}
	void Monster::OnCollisionStay(Collider* other)
	{
	}
	void Monster::OnCollisionExit(Collider* other)
	{
	}
}