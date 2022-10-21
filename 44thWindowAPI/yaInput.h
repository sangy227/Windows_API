#pragma once
#include "Common.h"

namespace ya {
	enum class eKeyCode {
		Q,W,E,R,T,Y,U,I,O,P,
		A,S,D,F,G,H,J,K,L,
		Z,X,C,V,B,N,M,
		End,
	};

	enum class eKeyState {
		DOWN,
		PRESSED,
		UP,
		NONE,
	};
	class Input
	{
	public:
		struct key
		{
			//나의 키 종류
			eKeyCode keyCode;
			//키보드 상태
			eKeyState state;
			bool bPressed;
		};

		 static void Initialize();
		 static void Tick();
		 static void Render(HDC hdc);
		 static eKeyState GetkeyState(eKeyCode keycode);

	private:
		static std::vector<key> mKeys;
	};
}

