#include "yaGameObject.h"

namespace ya {
	GameObject::GameObject()
		: mPos{ 0.0f, 0.0f }
		, mScale{ 1.0f, 1.0f }
	{
	}
	GameObject::~GameObject()
	{

		for (Component* component : mComponent)
		{
			if (component == nullptr) {
				continue;
			}
			delete component;
			component = nullptr;
		}
	}
	void GameObject::Initialize()
	{

	}


	void GameObject::Tick()
	{
		//모든 컴포넌트를 Tick호출
		for (Component* component : mComponent)
		{
			if (component == nullptr) {
				continue;
			}
			component->Tick();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		//모든 컴포넌트를 Render 호출
		for (Component* component : mComponent)
		{
			if (component == nullptr) {
				continue;
			}
			component->Render(hdc);
		}
	}
	void GameObject::AddComponent(Component* component)
	{
		mComponent.push_back(component);
	}
}