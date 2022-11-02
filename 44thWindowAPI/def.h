#pragma once

#define KEY_PREESE(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::PRESSED
#define KEY_DOWN(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::DOWN
#define KEY_UP(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::UP	


	enum class eSceneType
	{
		Logo,
		Title,
		Play,
		End,
		Max,
	};

	enum class ePenColor
	{
		Red,
		Green,
		Blue,
		End,

	};

	enum class eBrushColor
	{
		Transparent,//≈ı∏Ì
		Black,
		Gray,//167,0,67
		White,
		End,

	};

	enum class eComponentType
	{
		Aimator,
		Collider,
		Sound,
		End,
		
	};

#define _COLLIDER_LAYER 16
	enum class eColliderLayer
	{
		Default,
		BackGround,
		Tile,
		Player,
		Player_Projecttile,
		Monster,
		monster_ProjectTile,

		UI = _COLLIDER_LAYER-1,
		End = _COLLIDER_LAYER,

	};

	union ColliderID
	{
		
		struct 
		{
			UINT32 left;
			UINT32 right;
		};
		UINT64 ID;
	};

	enum class eCameraEffect
	{
		FadeIn,
		FadeOut,
		None,
	};