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
#include "yaRigidbody.h"
#include "yaUIManager.h"


namespace ya 
{
	Player::Player()
		: mSpeed(1.0f)
		, mTime(0.0f)
		, mMisiileDir(Vector2::Zero)
		, mHp(100)
	{
		SetName(L"Player");
		SetPos({ 520.0f, 770.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImages[0] == nullptr)
		{
			mImages[0] = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Player1.bmp");
			mImages[1] = Resources::Load<Image>(L"attack", L"..\\Resources\\Image\\attack.bmp");
			mImages[2] = Resources::Load<Image>(L"Walk", L"..\\Resources\\Image\\Walk.bmp");
			mImages[3] = Resources::Load<Image>(L"BowAttack", L"..\\Resources\\Image\\BowAttack.bmp");
			mImages[4] = Resources::Load<Image>(L"SearchPack", L"..\\Resources\\Image\\mc_searchPack.bmp");
		}

		mAnimator = new AniMator();

		//각각 스프라이트 형식 불러오기 방법
		//알파 채널로 안해서 이미지 로드하면 버그남
		/*mAnimator->CreateAnimations(L"..\\Resources\\Animations\\Player\\Idle"
			, L"PlaneIdle");*/
		//각각 스프라이트 형식 불러오기 방법



		mAnimator->CreateAnimation(L"Idle", mImages[0]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f,-48.0f), 4, 0.2f);

		mAnimator->CreateAnimation(L"attack", mImages[1]
			, Vector2(0.0f, 0.0f), Vector2(64.0f, 48.0f)
			, Vector2(-36.0f, -48.0f), 8, 0.05f);

		mAnimator->CreateAnimation(L"BowAttack", mImages[3]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 8, 0.07f);

		mAnimator->CreateAnimation(L"Walk", mImages[2]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 8, 0.1f);

		mAnimator->CreateAnimation(L"SearchPack", mImages[4]
			, Vector2(0.0f, 0.0f), Vector2(64.0f, 48.0f)
			, Vector2(-72.0f, -48.0f), 2, 0.4f);

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

		
		//mAnimator->FindEvents(L"attack")->mCompleteEvent = std::bind(&Player::WalkComplete, this);
		//키입력으로 내렸음 코드들
		/*mAnimator->GetCompleteEvent(L"attack") = std::bind(&Player::WalkComplete, this);
		mAnimator->GetCompleteEvent(L"BowAttack") = std::bind(&Player::WalkComplete, this);*/
		

		AddComponent(mAnimator);

		Collider* collider = new Collider();
		AddComponent(collider);
		collider->SetPos(GetPos());

		//오른쪽 아래쪽 충돌체 각각 만드는 코드
		/*collider->SetOffset(Vector2(0.0f, 50.0f));
		collider->SetScale(Vector2(10.0f, 10.0f));

		Collider* coliider2 = new Collider();
		AddComponent(coliider2);

		coliider2->SetOffset(Vector2(60.0f, 0.0f));
		coliider2->SetScale(Vector2(10.0f, 10.0f));*/


		/*Rigidbody* rigidbody = new Rigidbody();
		AddComponent(rigidbody);*/
		//윗줄 아랫줄 같은거 같은거
		AddComponent<Rigidbody>();

		//Camera::SetTarget(this);

		mCoff = 0.1f;
		mMisiileDir = Vector2::One;

		

		

		/*BackPack* backPack = new BackPack();
		Scene* playScene = SceneManager::GetPlayScene();
		playScene->AddGameObject(backPack, eColliderLayer::Player_Projecttile);*/
	}


	Player::~Player()
	{

	}

	void Player::Tick()
	{
		GameObject::Tick();


		//키보드 입력
		//Vector2 pos = GetPos();






		if (KEY_PREESE(eKeyCode::W))
		{
			//pos.y -= 120.0f * Time::DeltaTime();
			GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, -200.0f));
		}
		//if (KEY_PREESE(eKeyCode::S))
		//{
		//	//pos.y += 120.0f * Time::DeltaTime();
		//}
		if (KEY_PREESE(eKeyCode::A))
		{
			//pos.x -= 120.0f * Time::DeltaTime();
			GetComponent<Rigidbody>()->AddForce(Vector2(-200.0f, 0.0f));

		}
		//if (KEY_PREESE(eKeyCode::D))
		//{
		//	//pos.x += 120.0f * Time::DeltaTime();
		//}







		if (KEY_DOWN(eKeyCode::SPACE))
		{
			Rigidbody* rigidbody = GetComponent<Rigidbody>();
			Vector2 velocity = rigidbody->GetVelocity();
			velocity.y = -500.f;
			rigidbody->SetVelocity(velocity);

			rigidbody->SetGround(false);

			UIManager::Pop(eUIType::OPTION);
		}

		/*if (KEY_DOWN(eKeyCode::W))
		{
			mAnimator->Play(L"MoveUp", true);
		}*/
		if (KEY_DOWN(eKeyCode::S))
		{
			mAnimator->Play(L"SearchPack", true);
		}
		/*if (KEY_DOWN(eKeyCode::A))
		{
			mAnimator->Play(L"MoveLeft", true);
		}*/
		if (KEY_DOWN(eKeyCode::D))
		{
			mAnimator->Play(L"Walk", true);
		}







		/*if (KEY_UP(eKeyCode::W))
		{
			mAnimator->Play(L"Idle", true);	
		}*/
		if (KEY_UP(eKeyCode::S))
		{
			mAnimator->Play(L"Idle", true);
		}
		/*if (KEY_UP(eKeyCode::A))
		{
			mAnimator->Play(L"Idle", true);
		}*/
		if (KEY_UP(eKeyCode::D))
		{
			mAnimator->Play(L"Idle", true);
		}








		//마우스 우클릭
		if (KEY_DOWN(eKeyCode::RBTN)) {

			mAnimator->Play(L"BowAttack", true);
			mAnimator->GetCompleteEvent(L"BowAttack") = std::bind(&Player::WalkComplete, this);
			
		}

		//마우스 좌클릭
		if (KEY_DOWN(eKeyCode::LBTN)) {
			Vector2 pos = GetPos();
			pos.x += 120.0f;
			SetPos(pos);

			mAnimator->Play(L"attack", true);
			mAnimator->GetCompleteEvent(L"attack") = std::bind(&Player::WalkComplete, this);
			//mAnimator->FindEvents(L"attack")->mCompleteEvent = std::bind(&Player::WalkComplete, this);

			//미사일 나가게 하기~
			if (false)
			{
				Missile* missile = new Missile();

				Scene* playScene = SceneManager::GetPlayScene();
				playScene->AddGameObject(missile, eColliderLayer::Player_Projecttile);

				Vector2 playerPos = GetPos();
				Vector2 playerScale = GetScale() / 2.0f;

				missile->SetPos(playerPos);
				missile->mDestPos = Vector2::One; // = Input::GetMousePos();
				//missile->mDir = missile->mDestPos - pos;

				mMisiileDir = math::Rotate(mMisiileDir, 5.0f);
				missile->mDir = mMisiileDir;
			}


			//missile->mDir = Vector2(mCoff, -1.0f + mCoff);
			//mCoff -= 0.1f;
		}
		if (KEY_DOWN(eKeyCode::I))
		{
			BackPack* backPack = new BackPack();
			Scene* playScene = SceneManager::GetPlayScene();
			playScene->AddGameObject(backPack, eColliderLayer::Player_Projecttile);
		}

		//움직인 Pos값 다시 설정
		//SetPos(pos);
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
		Vector2 pos = GetPos();
		pos.x = 520.0f;
		pos.y = 770.0f;
		SetPos(pos);


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