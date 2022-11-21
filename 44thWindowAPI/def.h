#pragma once

#define KEY_PREESE(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::PRESSED
#define KEY_DOWN(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::DOWN
#define KEY_UP(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::UP	


	enum class eSceneType
	{
		Logo,
		Title,
		PlayOne,
		PlayTwo,
		PlayThree,
		PlayFour,
		End,
		Tool,
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
		Rigidbody,
		Collider,
		Animator,
		Sound,
		End,
		
	};

#define _COLLIDER_LAYER 16
	enum class eColliderLayer
	{
		Default,

		//gameobject
		BackGround,
		Tile,
		Player,
		Player_Projecttile,
		Monster,
		monster_ProjectTile,
		Ground,

		//ui
		BackPack,
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
	typedef ColliderID TileID;

	enum class eCameraEffect
	{
		FadeIn,
		FadeOut,
		None,
	};

	enum class eUIType
	{
		LogoButton1,
		LogoButton2,
		LogoButton3,
		LogoButton4,
		LogoButton5,
		LogoButton6,

		TitleDefault,
		TitleSelectBg,
		McIcon,
		ToteIcon,
		Cr8Icon,
		SetchelIcon,
		Mc_Info,
		Tote_Info,
		Cr8_Info,
		Setchel_Info,

		HP,
		MP,
		SHOP,
		INVENTORY,
		OPTION,

		END,
	};


#define TILE_SIZE 32
#define TILE_SCALE 2

#define TILE_LINE_X 8
#define TILE_LINE_Y 3