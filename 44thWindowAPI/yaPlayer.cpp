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
#include "yaUIBase.h"

namespace ya 
{
	Player::Player()
		: mSpeed(1.0f)
		, mTime(0.0f)
		, mMisiileDir(Vector2::Zero)
		, mHp(100)
		, mState(eState::Attack)
		, mAttackCount(0)
		, mDamageCount(0)
	{
		SetName(L"Player");
		SetPos({ 520.0f, 770.0f });
		SetScale({ 0.0f, 0.0f });

		if (mImages[0] == nullptr)
		{
			mImages[0] = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Player\\MC\\Rogue\\mc_idle-1.bmp");
			mImages[1] = Resources::Load<Image>(L"attack", L"..\\Resources\\Image\\Player\\MC\\Rogue\\rogue_attack_spritesheet.bmp");
			mImages[2] = Resources::Load<Image>(L"mc_Walk", L"..\\Resources\\Image\\Player\\MC\\Rogue\\rogue_walk_spritesheet.bmp");
			mImages[3] = Resources::Load<Image>(L"BowAttack", L"..\\Resources\\Image\\Player\\MC\\Rogue\\mc_bow_shot.bmp");
			mImages[4] = Resources::Load<Image>(L"SearchPack", L"..\\Resources\\Image\\Player\\MC\\Rogue\\mc_searchPack.bmp");

			mImages[5] = Resources::Load<Image>(L"mc_map", L"..\\Resources\\Image\\Player\\MC\\Rogue\\mc_map.bmp");
			mImages[6] = Resources::Load<Image>(L"mc_hurt-1", L"..\\Resources\\Image\\Player\\MC\\Rogue\\mc_hurt-1.bmp");
			mImages[7] = Resources::Load<Image>(L"mc_winsmall", L"..\\Resources\\Image\\Player\\MC\\Rogue\\mc_winsmall.bmp");
			mImages[8] = Resources::Load<Image>(L"mc_die", L"..\\Resources\\Image\\Player\\MC\\Rogue\\mc_die.bmp");
			mImages[9] = Resources::Load<Image>(L"mc_useItem-2", L"..\\Resources\\Image\\Player\\MC\\Rogue\\mc_useItem-2.bmp");
			mImages[10] = Resources::Load<Image>(L"mc_block-4", L"..\\Resources\\Image\\Player\\MC\\Rogue\\mc_block-4.bmp");
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

		//추가된부분
		mAnimator->CreateAnimation(L"Map", mImages[5]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.2f);

		mAnimator->CreateAnimation(L"hurt", mImages[6]
			, Vector2(0.0f, 0.0f), Vector2(64.0f, 48.0f)
			, Vector2(-36.0f, -48.0f), 5, 0.05f);

		mAnimator->CreateAnimation(L"winsmall", mImages[7]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 4, 0.2f);

		mAnimator->CreateAnimation(L"die", mImages[8]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 2, 1.0f);

		mAnimator->CreateAnimation(L"useitem", mImages[9]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 1, 1.0f);

		mAnimator->CreateAnimation(L"block", mImages[10]
			, Vector2(0.0f, 0.0f), Vector2(48.0f, 48.0f)
			, Vector2(-24.0f, -48.0f), 1, 1.0f);


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

		//추가
	}


	Player::~Player()
	{

	}

	void Player::Tick()
	{
		GameObject::Tick();


		//키보드 입력
		//Vector2 pos = GetPos();
		
		//fsm 쿠키런
		/*switch (mState)
		{
		case ya::Player::eState::Attack:
		{

		}
			break;
		case ya::Player::eState::Bow:
		{

		}
			break;
		case ya::Player::eState::Death:
		{

		}
			break;
		default:
			break;
		}*/




		//if (KEY_PREESE(eKeyCode::W))
		//{
		//	pos.y -= 120.0f * Time::DeltaTime();
		//	GetComponent<Rigidbody>()->AddForce(Vector2(0.0f, -200.0f));

		//	여기서 11/22일 꺼 코드 추가 실험 lerp
		//}
		//if (KEY_PREESE(eKeyCode::S))
		//{
		//	//pos.y += 120.0f * Time::DeltaTime();
		//}
		//if (KEY_PREESE(eKeyCode::A))
		//{
		//	pos.x -= 120.0f * Time::DeltaTime();
		//	GetComponent<Rigidbody>()->AddForce(Vector2(-200.0f, 0.0f));

		//}
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

		
		if (KEY_DOWN(eKeyCode::Q))
		{
			if (mAttackCount == 0)
			{
				Vector2 pos = GetPos();
				pos.x += 120.0f;
				SetPos(pos);

				mAnimator->Play(L"attack", true);
				mAnimator->GetCompleteEvent(L"attack") = std::bind(&Player::WalkComplete, this);

				mAttackCount++;
			}
		}
		if (KEY_DOWN(eKeyCode::W))
		{
			mAnimator->Play(L"BowAttack", true);
			mAnimator->GetCompleteEvent(L"BowAttack") = std::bind(&Player::WalkComplete, this);
		}
		if (KEY_DOWN(eKeyCode::E) /*|| (!(mIconState == Player_Icon_Move::DEFALUT))*/ )
		{
			mAnimator->Play(L"Walk", true);
			mBgStatus = BgStatus::MOVE;
			
		}
		if (KEY_DOWN(eKeyCode::R))
		{
			mAnimator->Play(L"SearchPack", true);
		}
		if (KEY_DOWN(eKeyCode::T))
		{
			mAnimator->Play(L"Map", true);
		}
		if (KEY_DOWN(eKeyCode::Y))
		{
			if (mDamageCount == 0) {
				Vector2 pos = GetPos();
				pos.x -= 100.0f;
				SetPos(pos);

				mAnimator->Play(L"hurt", true);
				mAnimator->GetCompleteEvent(L"hurt") = std::bind(&Player::WalkComplete, this);
				mDamageCount++;
			}
		}
		if (KEY_DOWN(eKeyCode::A))
		{
			mAnimator->Play(L"winsmall", true);
		}
		if (KEY_DOWN(eKeyCode::S))
		{
			mAnimator->Play(L"die", true);
		}
		if (KEY_DOWN(eKeyCode::D))
		{
			mAnimator->Play(L"useitem", true);
		}
		if (KEY_DOWN(eKeyCode::F))
		{
			mAnimator->Play(L"block", true);
		}


		

		if (KEY_UP(eKeyCode::E) )
		{
			mAnimator->Play(L"Idle", true);
			mBgStatus = BgStatus::DEFALUT;
		}
		if (KEY_UP(eKeyCode::R))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::T))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::A))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::S))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::D))
		{
			mAnimator->Play(L"Idle", true);
		}
		if (KEY_UP(eKeyCode::F))
		{
			mAnimator->Play(L"Idle", true);
		}







		








		//마우스 우클릭
		/*if (KEY_DOWN(eKeyCode::RBTN)) {

			mAnimator->Play(L"BowAttack", true);
			mAnimator->GetCompleteEvent(L"BowAttack") = std::bind(&Player::WalkComplete, this);
			
		}*/

		//마우스 좌클릭
		//if (KEY_DOWN(eKeyCode::LBTN)) {
		//	Vector2 pos = GetPos();
		//	pos.x += 120.0f;
		//	SetPos(pos);

		//	mAnimator->Play(L"attack", true);
		//	mAnimator->GetCompleteEvent(L"attack") = std::bind(&Player::WalkComplete, this);
		//	//mAnimator->FindEvents(L"attack")->mCompleteEvent = std::bind(&Player::WalkComplete, this);

		//	//미사일 나가게 하기~
		//	if (false)
		//	{
		//		Missile* missile = new Missile();

		//		Scene* playScene = SceneManager::GetPlayScene();
		//		playScene->AddGameObject(missile, eColliderLayer::Player_Projecttile);

		//		Vector2 playerPos = GetPos();
		//		Vector2 playerScale = GetScale() / 2.0f;

		//		missile->SetPos(playerPos);
		//		missile->mDestPos = Vector2::One; // = Input::GetMousePos();
		//		//missile->mDir = missile->mDestPos - pos;

		//		mMisiileDir = math::Rotate(mMisiileDir, 5.0f);
		//		missile->mDir = mMisiileDir;
		//	}


			//missile->mDir = Vector2(mCoff, -1.0f + mCoff);
			//mCoff -= 0.1f;
		//}
		/*if (KEY_DOWN(eKeyCode::I))
		{
			BackPack* backPack = new BackPack();
			Scene* playScene = SceneManager::GetPlayScene();
			playScene->AddGameObject(backPack, eColliderLayer::Player_Projecttile);
		}*/

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
		mAttackCount = 0;
		mDamageCount = 0;
		/*Missile* missile = new Missile();

		Scene* playScene = SceneManager::GetPlayScene();
		playScene->AddGameObject(missile, eColliderLayer::Player_Projecttile);

		Vector2 playerPos = GetPos();
		Vector2 playerScale = GetScale() / 2.0f;
		Vector2 missileScale = missile->GetScale();

		missile->SetPos((playerPos + playerScale) - (missileScale / 2.0f));*/
	}
	void Player::Player_Move()
	{
		mAnimator->Play(L"Walk", true);
	}

	void Player::Player_Idel()
	{
		mAnimator->Play(L"Idle", true);
	}

	void Player::Player_Attack()
	{
		if (mAttackCount == 0)
		{
			Vector2 pos = GetPos();
			pos.x += 120.0f;
			SetPos(pos);

			mAnimator->Play(L"attack", true);
			mAnimator->GetCompleteEvent(L"attack") = std::bind(&Player::WalkComplete, this);

			mAttackCount++;
		}
	}

	void Player::Player_BowAttack()
	{
		mAnimator->Play(L"BowAttack", true);
		mAnimator->GetCompleteEvent(L"BowAttack") = std::bind(&Player::WalkComplete, this);
	}

	void Player::Player_SearchPack()
	{
		mAnimator->Play(L"SearchPack", true);
	}

	void Player::Player_Map()
	{
		mAnimator->Play(L"Map", true);
	}

	void Player::Player_hurt()
	{
		if (mDamageCount == 0) {
			Vector2 pos = GetPos();
			pos.x -= 100.0f;
			SetPos(pos);

			mAnimator->Play(L"hurt", true);
			mAnimator->GetCompleteEvent(L"hurt") = std::bind(&Player::WalkComplete, this);
			mDamageCount++;
		}
	}

	void Player::Player_winsmall()
	{
		mAnimator->Play(L"winsmall", true);
	}

	void Player::Player_die()
	{
		mAnimator->Play(L"die", true);
	}

	void Player::Player_useitem()
	{
		mAnimator->Play(L"useitem", true);
		mAnimator->GetCompleteEvent(L"useitem") = std::bind(&Player::WalkComplete, this);
	}

	void Player::Player_block()
	{
		mAnimator->Play(L"block", true);
	}

}