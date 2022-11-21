#include "yaUIManager.h"
#include "yaHUD.h"
#include "yaButton.h"
#include "yaPanel.h"

#include "LogoButton1.h"
#include "LogoButton2.h"
#include "LogoButton3.h"
#include "LogoButton4.h"
#include "LogoButton5.h"
#include "LogoButton6.h"

#include "TitleDefault.h"
#include "McIcon.h"
#include "ToteIcon.h"
#include "Cr8Icon.h"
#include "SetchelIcon.h"

namespace ya {
	std::unordered_map <eUIType, UIBase*> UIManager::mUIs;
	std::queue<eUIType> UIManager::mRequestUIQueue;
	std::stack<UIBase*> UIManager::mUIBases;
	UIBase* UIManager::mCurrentData = nullptr;


	void UIManager::Initialize()
	{
		// 여기에서 ui 메모리에 할당하면 된다.

		/*로고버튼 모음*/
		LogoButtonFull();

		/*플레이어 선택창*/
		PlayerSelectFull();


		//Button* button = new Button(eUIType::HP);
		//mUIs.insert(std::make_pair(eUIType::HP, button));
		//button->SetPos(Vector2(0.0f, 0.0f));
		////newUI->SetSize(Vector2(500.0f, 100.0f));
		//button->ImageLoad(L"HPBAR", L"..\\Resources\\Image\\HPBAR.bmp");

		/*HUD* hud = new HUD(eUIType::MP);
		mUIs.insert(std::make_pair(eUIType::MP, hud));
		hud->SetPos(Vector2(0.0f, 100.0f));
		hud->ImageLoad(L"HPBAR", L"..\\Resources\\Image\\HPBAR.bmp");*/

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

	void UIManager::LogoButtonFull()
	{
		LogoButton1* logobutton1 = new LogoButton1(eUIType::LogoButton1);
		mUIs.insert(std::make_pair(eUIType::LogoButton1, logobutton1));
		logobutton1->SetPos(Vector2(620.0f, 470.0f));
		//newUI->SetSize(Vector2(500.0f, 100.0f));
		logobutton1->ImageLoad(L"LogoButton1", L"..\\Resources\\Image\\LogoButton.bmp");

		LogoButton2* logobutton2 = new LogoButton2(eUIType::LogoButton2);
		mUIs.insert(std::make_pair(eUIType::LogoButton2, logobutton2));
		logobutton2->SetPos(Vector2(620.0f, 530.0f));
		//newUI->SetSize(Vector2(500.0f, 100.0f));
		logobutton2->ImageLoad(L"LogoButton2", L"..\\Resources\\Image\\LogoButton.bmp");

		LogoButton3* logobutton3 = new LogoButton3(eUIType::LogoButton3);
		mUIs.insert(std::make_pair(eUIType::LogoButton3, logobutton3));
		logobutton3->SetPos(Vector2(620.0f, 590.0f));
		//newUI->SetSize(Vector2(500.0f, 100.0f));
		logobutton3->ImageLoad(L"LogoButton3", L"..\\Resources\\Image\\LogoButton.bmp");

		LogoButton4* logobutton4 = new LogoButton4(eUIType::LogoButton4);
		mUIs.insert(std::make_pair(eUIType::LogoButton4, logobutton4));
		logobutton4->SetPos(Vector2(620.0f, 650.0f));
		//newUI->SetSize(Vector2(500.0f, 100.0f));
		logobutton4->ImageLoad(L"LogoButton4", L"..\\Resources\\Image\\LogoButton.bmp");

		LogoButton5* logobutton5 = new LogoButton5(eUIType::LogoButton5);
		mUIs.insert(std::make_pair(eUIType::LogoButton5, logobutton5));
		logobutton5->SetPos(Vector2(620.0f, 710.0f));
		//newUI->SetSize(Vector2(500.0f, 100.0f));
		logobutton5->ImageLoad(L"LogoButton5", L"..\\Resources\\Image\\LogoButton.bmp");

		LogoButton6* logobutton6 = new LogoButton6(eUIType::LogoButton6);
		mUIs.insert(std::make_pair(eUIType::LogoButton6, logobutton6));
		logobutton6->SetPos(Vector2(620.0f, 770.0f));
		//newUI->SetSize(Vector2(500.0f, 100.0f));
		logobutton6->ImageLoad(L"LogoButton6", L"..\\Resources\\Image\\LogoButton.bmp");
	}

	void UIManager::PlayerSelectFull()
	{
		McIcon* mcicon = new McIcon(eUIType::McIcon);
		mUIs.insert(std::make_pair(eUIType::McIcon, mcicon));
		mcicon->SetPos(Vector2(30.0f, 170.0f));
		mcicon->ImageLoad(L"mcicon", L"..\\Resources\\Image\\Object\\McIcon.bmp");

		ToteIcon* toteicon = new ToteIcon(eUIType::ToteIcon);
		mUIs.insert(std::make_pair(eUIType::ToteIcon, toteicon));
		toteicon->SetPos(Vector2(30.0f, 300.0f));
		toteicon->ImageLoad(L"toteicon", L"..\\Resources\\Image\\Object\\ToteIcon.bmp");

		Cr8Icon* cr8icon = new Cr8Icon(eUIType::Cr8Icon);
		mUIs.insert(std::make_pair(eUIType::Cr8Icon, cr8icon));
		cr8icon->SetPos(Vector2(30.0f, 430.0f));
		cr8icon->ImageLoad(L"cr8icon", L"..\\Resources\\Image\\Object\\Cr8Icon.bmp");

		SetchelIcon* setchelicon = new SetchelIcon(eUIType::SetchelIcon);
		mUIs.insert(std::make_pair(eUIType::SetchelIcon, setchelicon));
		setchelicon->SetPos(Vector2(30.0f, 560.0f));
		setchelicon->ImageLoad(L"setchelicon", L"..\\Resources\\Image\\Object\\SetchelIcon.bmp");


		TitleDefault* titledefault = new TitleDefault(eUIType::TitleDefault);
		mUIs.insert(std::make_pair(eUIType::TitleDefault, titledefault));
		titledefault->ImageLoad(L"TitleDefault", L"..\\Resources\\Image\\Object\\TitleDefault.bmp");
		titledefault->SetPos(Vector2(250.0f, 50.0f));
		titledefault->AddChild(mcicon);
		titledefault->AddChild(toteicon);
		titledefault->AddChild(cr8icon);
		titledefault->AddChild(setchelicon);
	}

	

}