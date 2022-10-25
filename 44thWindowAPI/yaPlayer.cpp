#include "yaPlayer.h"
#include "yaTime.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaMissile.h"
#include "yaScene.h"
#include "yaImage.h"
#include "yaResources.h"

//여기도 추가
namespace ya {
	Player::Player()
		: mSpeed(1.0f)
	{
		//예시 문제 기본값
		SetPos({ 100.0f, 100.0f });
		SetScale({ 100.0f, 100.0f });

		if (mImage == nullptr)
		{
			mImage = Resources<Image>::Load(L"Player", L"..\\Resources\\Image\\Player.bmp");

			//Resources<Sound>::Load(L"Player", L"..\\Resources\\Image\\Player.bmp");
			//mImage->Load(L"..\\Resources\\Image\\Player.bmp");
		}


	}
	Player::~Player()
	{
	}
	void Player::Tick()
	{
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

		if (KEY_DOWN(eKeyCode::SPACE)) {
			Missile* missile = new Missile();

			Scene* playScene = SceneManager::GetplayScene();
			playScene->AddGameObject(missile);

			Vector2 playerPos = GetPos();
			Vector2 playerScale = GetScale() / 2.0f;

			Vector2 missileScale = missile->GetScale();

			missile->SetPos((playerPos + playerScale) - (missileScale / 2.0f));
		}
		//움직인 Pos값 다시 설정
		SetPos(pos);

		


	}
	void Player::Render(HDC hdc)
	{
		//아래 주석 대체용 common파일에 추가함
		HBRUSH blueBrush = CreateSolidBrush(RGB(153,204,255));
		//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);
		//(HBRUSH)SelectObject(hdc, oldBrush);
		//DeleteObject(oldBrush);
		Brush brush(hdc, blueBrush);

		
		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		Pen pen(hdc, redPen);



		

		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		//Rectangle(hdc, pos.x, pos.y, pos.x + scale.x, pos.y + scale.y);

		//이미지고 사운드고 똑같이 로드할수있게



		BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(),mImage->GetHeight(),
			mImage->GetDC(),0,0,SRCCOPY);
	}
}