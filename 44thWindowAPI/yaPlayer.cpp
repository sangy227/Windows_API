#include "yaPlayer.h"
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
#include "yaBackPack.h"


namespace ya 
{
	Player::Player()
		: mSpeed(1.0f)
	{
		SetName(L"Player");
		SetPos({ 520.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Player1.bmp");
			mImage2 = Resources::Load<Image>(L"attack", L"..\\Resources\\Image\\attack.bmp");

		}

		mAnimator = new AniMator();
		mAnimator->CreateAnimation(L"Idle", mImage
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f,-48.0f), 4, 0.4f);

		mAnimator->CreateAnimation(L"attack", mImage2
			, Vector2(0.0f, 0.0f), Vector2(64.0f, 48.0f)
			, Vector2(-36.0f, -48.0f), 4, 0.1f);

		/*mAnimator->CreateAnimation(L"MoveDown", mImage
			, Vector2(0.0f, 520.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 10, 0.1f);
		mAnimator->CreateAnimation(L"MoveLeft", mImage
			, Vector2(0.0f, 650.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 10, 0.1f);
		mAnimator->CreateAnimation(L"MoveUp", mImage
			, Vector2(0.0f, 780.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 10, 0.1f);
		mAnimator->CreateAnimation(L"MoveRight", mImage
			, Vector2(0.0f, 910.0f), Vector2(120.0f, 130.0f)
			, Vector2(5.0f, -20.0f), 10, 0.1f);*/

		mAnimator->Play(L"Idle", true);

		/*mAnimator->mCompleteEvent = std::bind(&Player::WalkComplete, this);*/

		AddComponent(mAnimator);
		AddComponent(new Collider());

		//Camera::SetTarget(this);





		BackPack* backPack = new BackPack();
		Scene* playScene = SceneManager::GetPlayScene();
		playScene->AddGameObject(backPack, eColliderLayer::Player_Projecttile);

	}
	Player::~Player()
	{

	}

	void Player::Tick()
	{
		GameObject::Tick();


		//키보드 입력
		Vector2 pos = GetPos();
		if (KEY_PREESE(eKeyCode::W))
		{
			pos.y -= 120.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::S))
		{
			pos.y += 120.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::A))
		{
			pos.x -= 120.0f * Time::DeltaTime();
		}
		if (KEY_PREESE(eKeyCode::D))
		{
			pos.x += 120.0f * Time::DeltaTime();
		}

		/*if (KEY_DOWN(eKeyCode::W))
		{
			mAnimator->Play(L"MoveUp", true);
		}
		if (KEY_DOWN(eKeyCode::S))
		{
			mAnimator->Play(L"MoveDown", true);
		}
		if (KEY_DOWN(eKeyCode::A))
		{
			mAnimator->Play(L"MoveLeft", true);
		}
		if (KEY_DOWN(eKeyCode::D))
		{
			mAnimator->Play(L"MoveRight", true);
		}*/

		/*if (KEY_UP(eKeyCode::W))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::S))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::A))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::D))
		{
			mAnimator->Play(L"Idle", true);
		}*/


		if (KEY_DOWN(eKeyCode::LBTN)) {

			mAnimator->Play(L"attack", true);
			mAnimator->mCompleteEvent = std::bind(&Player::WalkComplete, this);

			/*Missile* missile = new Missile();

			Scene* playScene = SceneManager::GetPlayScene();
			playScene->AddGameObject(missile, eColliderLayer::Player_Projecttile);

			Vector2 playerPos = GetPos();
			Vector2 playerScale = GetScale() / 2.0f;
			Vector2 missileScale = missile->GetScale();

			missile->SetPos((playerPos + playerScale) - (missileScale / 2.0f));*/
		}
		
		if (KEY_DOWN(eKeyCode::I))
		{
			BackPack* backPack = new BackPack();
			Scene* playScene = SceneManager::GetPlayScene();
			playScene->AddGameObject(backPack, eColliderLayer::Player_Projecttile);
		}
		//움직인 Pos값 다시 설정
		SetPos(pos);

		


	}
	void Player::Render(HDC hdc)
	{
		//아래 주석 대체용 common파일에 추가함
		//HBRUSH blueBrush = CreateSolidBrush(RGB(153,204,255));
		// 
		//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);
		//(HBRUSH)SelectObject(hdc, oldBrush);
		//DeleteObject(oldBrush);
		// 
		//Brush brush(hdc, blueBrush);

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//Pen pen(hdc, redPen);

		//Vector2 pos = GetPos();
		//Vector2 scale = GetScale();

		////Rectangle(hdc, pos.x, pos.y, pos.x + scale.x, pos.y + scale.y);

		////이미지고 사운드고 똑같이 로드할수있게
		//
		////크기변경이 안된다.
		///*BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(),mImage->GetHeight(),
		//	mImage->GetDC(),0,0,SRCCOPY);*/

		//
		//
		//Vector2 finalPos;
		//finalPos.x = (pos.x - mImage->GetWidth() * (scale.x / 2.0f));
		//finalPos.y = (pos.y - mImage->GetHeight() * (scale.y / 2.0f));

		//Vector2 rect;
		//rect.x = mImage->GetWidth() * scale.x;
		//rect.y = mImage->GetHeight() * scale.y;

		//finalPos = Camera::CalculatePos(finalPos);

		////그리기
		//TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
		//	, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
		//	, RGB(255, 0, 255));

		GameObject::Render(hdc);
		
	}
	void Player::OnCollisionEnter(Collider* other)
	{

	}
	void Player::OnCollisionStay(Collider* other)
	{

	}
	void Player::OnCollisionExit(Collider* other)
	{

	}
	void Player::WalkComplete()
	{
		mAnimator->Play(L"Idle", true);

		/*Missile* missile = new Missile();

		Scene* playScene = SceneManager::GetPlayScene();
		playScene->AddGameObject(missile, eColliderLayer::Player_Projecttile);

		Vector2 playerPos = GetPos();
		Vector2 playerScale = GetScale() / 2.0f;
		Vector2 missileScale = missile->GetScale();

		missile->SetPos((playerPos + playerScale) - (missileScale / 2.0f));*/
	}
}