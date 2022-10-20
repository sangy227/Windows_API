#include "yaGameObject.h"

namespace ya {
	GameObject::GameObject()
		: mPos{ 0.0f, 0.0f }
		, mScale{ 1.0f, 1.0f }
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Initialize()
	{
	}
	void GameObject::Tick()
	{
	}
	void GameObject::Render(HDC hdc)
	{
	}
}