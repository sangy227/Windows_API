#include "yaPlayer.h"

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
		if (GetAsyncKeyState('W') & 0x8000)
		{
			pos.y -= 0.01f;
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			pos.y += 0.01f;
		}
		if (GetAsyncKeyState('A') & 0x8000)
		{
			pos.x -= 0.01f;
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			pos.x += 0.01f;
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