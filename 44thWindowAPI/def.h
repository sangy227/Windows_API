#pragma once
#define KEY_PREESE(KEY) ya::Input::GetkeyState(KEY) == ya::eKeyState::PRESSED
#define KEY_DOWN(KEY) ya::Input::GetkeyState(KEY) == ya::eKeyState::DOWN
#define KEY_UP(KEY) ya::Input::GetkeyState(KEY) == ya::eKeyState::UP	

enum class eSceneType
{
	Logo,
	Title,
	Play,
	End,
	Max,
};