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
		Transparent,//癱貲
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

		/*天天天天天天天天天天天天天天天天天天天天天天天天*/

		McIcon,
		ToteIcon,
		Cr8Icon,
		SetchelIcon,

		Mc_Info,
		Tote_Info,
		Cr8_Info,
		Setchel_Info,

		TitleDefault,
		TitleSelectBg,
		TitleSelectBg2,
		TitleSelectBg3,
		TitleSelectBg4,

		TitleSelectBg5,
		TitleSelectBg6,

		TitleSelectBg7,

		TitleSelectBg8,

		TitleSelectButton1,
		TitleSelectButton2,

		/*天天天天天天天天天天天天天天天天天天天天天天天天*/

		TopLayerDefault,
		Book_Icon,
		Stats_Icon,
		Save_Icon,
		Option_Icon,
		Map_Icon,
		Back_Icon,

		Inventory2,
		Map_bg,
		Enter_Button,

		TestButton,
		TestSword,

		/*天天天天天天天天天天天天天天天天天天天天天天天天*/

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