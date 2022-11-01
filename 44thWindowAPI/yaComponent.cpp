#include "yaComponent.h"
#include "yaGameObject.h"


namespace ya {
	Component::Component(eComponentType type)
		:mType(type)
		,mOwner(nullptr)
	{

	}

	Component::~Component()
	{

	}
	
	void Component::Tick()
	{
		
	}

	void Component::Render(HDC hdc)
	{
	}
}