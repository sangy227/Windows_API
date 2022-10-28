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


//여기도 추가
namespace ya 
{
	Player::Player()
		: mSpeed(1.0f)
	{
		//예시 문제 기본값
		SetPos({ 350.0f, 700.0f });
		SetScale({ 3.0f, 3.0f });

		if (mImage == nullptr)
		{
			mImage = Resources::Load<Image>(L"Player", L"..\\Resources\\Image\\Player.bmp");

		}

		AddComponent(new AniMator());
		AddComponent(new Collider());

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
		
		//크기변경이 안된다.
		/*BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(),mImage->GetHeight(),
			mImage->GetDC(),0,0,SRCCOPY);*/

		
		//여기 변경
		Vector2 finalPos;
		finalPos.x = (pos.x - mImage->GetWidth() * (scale.x / 2.0f));
		finalPos.y = (pos.y - mImage->GetHeight() * (scale.y / 2.0f));

		Vector2 rect;
		rect.x = mImage->GetWidth() * scale.x;
		rect.y = mImage->GetHeight() * scale.y;

		//그리기
		TransparentBlt(hdc, finalPos.x, finalPos.y, rect.x, rect.y
			, mImage->GetDC(), 0, 0, mImage->GetWidth(), mImage->GetHeight()
			, RGB(255, 0, 255));

		GameObject::Render(hdc);
		
	}
}