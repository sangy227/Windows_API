#include "yaPlayer.h"
#include "yaTime.h"
#include "yaInput.h"
namespace ya {
	Player::Player()
		: mSpeed(1.0f)
	{
		//예시 문제 기본값
		SetPos({ 100.0f, 100.0f });
		SetScale({ 100.0f, 100.0f });
	}
	Player::~Player()
	{
	}
	void Player::Tick()
	{
		//키보드 입력
		Vector2 pos = GetPos();
		if (Input::GetkeyState(eKeyCode::W) == eKeyState::PRESSED)
		{
			pos.y -= 120.0f * Time::DeltaTime();
		}
		if (Input::GetkeyState(eKeyCode::S) == eKeyState::PRESSED)
		{
			pos.y += 120.0f * Time::DeltaTime();
		}
		if (Input::GetkeyState(eKeyCode::A) == eKeyState::PRESSED)
		{
			pos.x -= 120.0f * Time::DeltaTime();
		}
		if (Input::GetkeyState(eKeyCode::D) == eKeyState::PRESSED)
		{
			pos.x += 120.0f * Time::DeltaTime();
		}
		//움직인 Pos값 다시 설정
		SetPos(pos);
	}
	void Player::Render(HDC hdc)
	{
		Vector2 pos = GetPos();
		Vector2 scale = GetScale();

		Rectangle(hdc, pos.x, pos.y, pos.x + scale.x, pos.y + scale.y);

	}
}