#pragma once
#include "Common.h"


namespace ya
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring name) { mName = name; }
		std::wstring GetName() { return mName; }
		UINT32 GetID() { return mID; }

		enum class Player_Icon_Move
		{
			DEFALUT,
			LEFT,
			RIGHT,
			UP,
			DOWN,
			DOWN2,
			LEFT2,
			UP2,
		};
		static Player_Icon_Move mIconState;
	private:
		std::wstring mName;
		UINT32 mID;
	};
}
