#include "yaUIManager.h"
#include "yaHUD.h"
#include "yaButton.h"
#include "yaPanel.h"
#include "LogoButton1.h"
#include "LogoButton2.h"

namespace ya {
	std::unordered_map <eUIType, UIBase*> UIManager::mUIs;
	std::queue<eUIType> UIManager::mRequestUIQueue;
	std::stack<UIBase*> UIManager::mUIBases;
	UIBase* UIManager::mCurrentData = nullptr;


	void UIManager::Initialize()
	{
		// 여기에서 ui 메모리에 할당하면 된다.
		//Button* button = new Button(eUIType::HP);
		//mUIs.insert(std::make_pair(eUIType::HP, button));
		//button->SetPos(Vector2(0.0f, 0.0f));
		////newUI->SetSize(Vector2(500.0f, 100.0f));
		//button->ImageLoad(L"HPBAR", L"..\\Resources\\Image\\HPBAR.bmp");

		//Button* logobutton1 = new Button(eUIType::OPTION);
		//mUIs.insert(std::make_pair(eUIType::OPTION, logobutton1));
		//logobutton1->SetPos(Vector2(620.0f, 470.0f));
		////newUI->SetSize(Vector2(500.0f, 100.0f));
		//logobutton1->ImageLoad(L"LogoButton1", L"..\\Resources\\Image\\LogoButton.bmp");

		LogoButton1* logobutton1 = new LogoButton1(eUIType::LogoButton1);
		mUIs.insert(std::make_pair(eUIType::LogoButton1, logobutton1));
		logobutton1->SetPos(Vector2(620.0f, 470.0f));
		//newUI->SetSize(Vector2(500.0f, 100.0f));
		logobutton1->ImageLoad(L"LogoButton1", L"..\\Resources\\Image\\LogoButton.bmp");

		LogoButton2* logobutton2 = new LogoButton2(eUIType::LogoButton2);
		mUIs.insert(std::make_pair(eUIType::LogoButton2, logobutton2));
		logobutton2->SetPos(Vector2(620.0f, 530.0f));
		//newUI->SetSize(Vector2(500.0f, 100.0f));
		logobutton2->ImageLoad(L"LogoButton1", L"..\\Resources\\Image\\LogoButton.bmp");

		

		HUD* hud = new HUD(eUIType::MP);
		mUIs.insert(std::make_pair(eUIType::MP, hud));
		hud->SetPos(Vector2(0.0f, 100.0f));
		hud->ImageLoad(L"HPBAR", L"..\\Resources\\Image\\HPBAR.bmp");

		//Panel* panel = new Panel(eUIType::INVENTORY);
		//mUIs.insert(std::make_pair(eUIType::INVENTORY, panel));
		////newUI->SetIsFullScreen(true);
		////panel->ImageLoad(L"BackPack1", L"..\\Resources\\Image\\LogoButton.bmp");
		//panel->SetPos(Vector2(620.0f, 470.0f));
		//panel->AddChild(logobutton1);
		//panel->AddChild(logobutton2);

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
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase != nullptr)
			{
				uiBase->Tick();
			}
			uiBases.pop();
		}

		if (mRequestUIQueue.size() > 0)
		{
			//UI 로드 해줘
			eUIType requestUI = mRequestUIQueue.front();
			mRequestUIQueue.pop();

			OnLoad(requestUI);
		}
	}

	void UIManager::Render(HDC hdc)
	{
		std::stack<UIBase*> uiBases = mUIBases;
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			if (uiBase != nullptr)
			{
				uiBase->Render(hdc);
			}
			uiBases.pop();
		}
	}

	void UIManager::OnComplete(UIBase* addUI)
	{
		if (addUI == nullptr)
		{
			return;
		}
		addUI->Initialize();
		addUI->Active();
		addUI->Tick();

		if (addUI->GetIsFullScreen())
		{
			std::stack<UIBase*> uiBases = mUIBases;
			while (!uiBases.empty())
			{
				UIBase* uiBase = uiBases.top();
				uiBases.pop();

				if (uiBase->GetIsFullScreen())
				{
					uiBase->InActive();
				}
			}
		}

		mUIBases.push(addUI);

	}

	void UIManager::OnFail()
	{
		mCurrentData = nullptr;
	}

	void UIManager::Release()
	{
		for (auto ui : mUIs)
		{
			delete ui.second;
			ui.second = nullptr;
		}

	}

	void UIManager::Push(eUIType type)
	{
		mRequestUIQueue.push(type);
	}

	void UIManager::Pop(eUIType type)
	{
		if (mUIBases.size() <= 0)
			return;

		std::stack<UIBase*> tempStack;

		UIBase* uiBase = nullptr;
		while (mUIBases.size() > 0)
		{
			uiBase = mUIBases.top();
			mUIBases.pop();
			// pop하는 ui가 전체화면 일경우에,
			// 남은 ui중에 전체화면인 가장 상단의 ui 를 활성화 해주어야한다.
			if (uiBase->GetType() == type)
			{
				if (uiBase->GetIsFullScreen())
				{
					std::stack<UIBase*> uiBases = mUIBases;
					while (!uiBases.empty())
					{
						UIBase* uiBase = uiBases.top();
						uiBases.pop();

						if (uiBase->GetIsFullScreen())
						{
							uiBase->Active();
							break;
						}
					}
				}

				uiBase->UIClear();
			}
			else
			{
				tempStack.push(uiBase);
			}
		}

		while (tempStack.size())
		{
			uiBase = tempStack.top();
			tempStack.pop();
			mUIBases.push(uiBase);
		}
	}

	

}