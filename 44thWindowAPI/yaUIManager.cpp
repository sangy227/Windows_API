#include "yaUIManager.h"
namespace ya {
	std::unordered_map <eUIType, UIBase*> UIManager::mUIs;
	std::queue<eUIType> UIManager::mRequestUIQueue;
	std::stack<UIBase*> UIManager::mUIBases;
	UIBase* UIManager::mCurrentData;


	void UIManager::Initialize()
	{

		UIBase* newUI = new UIBase(eUIType::HP);
		mUIs.insert(std::make_pair(eUIType::HP, newUI));

		newUI = new UIBase(eUIType::MP);
		mUIs.insert(std::make_pair(eUIType::MP, newUI));

		newUI = new UIBase(eUIType::SHOP);
		mUIs.insert(std::make_pair(eUIType::SHOP, newUI));

		newUI = new UIBase(eUIType::INVENTORY);
		mUIs.insert(std::make_pair(eUIType::INVENTORY, newUI));

		newUI = new UIBase(eUIType::OPTION);
		mUIs.insert(std::make_pair(eUIType::OPTION, newUI));
	}

	void UIManager::OnLoad(eUIType type)
	{

		std::unordered_map<eUIType, UIBase*>::iterator iter = mUIs.find(type);
		if (iter == mUIs.end())
		{
			OnFail();
			return;
		}

		OnComplete(iter->second);
	}

	void UIManager::Tick()
	{
		if (mRequestUIQueue.size() > 0)
		{
			//UI ∑ŒµÂ «ÿ¡‡
			eUIType requestUI = mRequestUIQueue.front();
			mRequestUIQueue.pop();

			OnLoad(requestUI);
		}
	}

	void UIManager::Render(HDC hdc)
	{
	}

	void UIManager::OnComplete(UIBase* addUI)
	{
	}

	void UIManager::OnFail()
	{
	}

	void UIManager::Push(eUIType type)
	{
		mRequestUIQueue.push(type);

	}

	void UIManager::Pop(eUIType type)
	{
	}

}