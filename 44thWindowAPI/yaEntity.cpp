#include "yaEntity.h"


namespace ya
{
	ya::Entity::Player_Icon_Move Entity::mIconState = Player_Icon_Move::DEFALUT;

	Entity::Entity()
		: mName(L"")
		, mID((UINT32)this)

	{
	}
	Entity::~Entity()
	{
	}
}