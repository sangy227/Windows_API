#include "yaGameObject.h"
#include "yaTime.h"
namespace ya {
	ya::GameObject::BgStatus GameObject::mBgStatus = BgStatus::DEFALUT;

	GameObject::GameObject()
		: mPos({ 0.0f, 0.0f })
		, mScale{ 1.0f, 1.0f }
		, mDead(false)
		, mDeathTime(-100.0f)
		, mDeathTimeOn(false)
		, mHpHUD(nullptr)
		
	{
	}
	GameObject::GameObject(Vector2 position)
		: mPos{ position }
		, mScale{ 1.0f, 1.0f }
		, mDead(false)
		, mDeathTime(-100.0f)
		, mDeathTimeOn(false)
		

	{

	}
	GameObject::~GameObject()
	{

		for (Component* component : mComponents)
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
		DeathLoop();
		//모든 컴포넌트를 Tick호출
		for (Component* component : mComponents)
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
		for (Component* component : mComponents)
		{
			if (component == nullptr) {
				continue;
			}
			
			component->Render(hdc);
		}
	}
	void GameObject::OnCollisionEnter(Collider* other)
	{
	}
	void GameObject::OnCollisionStay(Collider* other)
	{
	}
	void GameObject::OnCollisionExit(Collider* other)
	{
	}
	void GameObject::AddComponent(Component* component)
	{
		if (component == nullptr) {
			return;
		}
			
		mComponents.push_back(component);
		component->mOwner = this;
	}
	void GameObject::DeathLoop()
	{
		if (mDeathTimeOn == true)
		{
			mDeathTime -= Time::DeltaTime();
			if (mDeathTime <= 0.0f)
				Death();
		}
	}
}