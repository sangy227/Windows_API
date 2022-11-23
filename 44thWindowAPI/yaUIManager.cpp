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
#include "TitleSelectBg.h"
#include "TitleSelectBg2.h"
#include "TitleSelectBg3.h"
#include "TitleSelectBg4.h"

#include "TitleSelectBg5.h"
#include "TitleSelectBg6.h"

#include "TitleSelectBg7.h"

#include "TitleSelectBg8.h"

#include "TitleSelectButton1.h"
#include "TitleSelectButton2.h"

#include "McIcon.h"
#include "ToteIcon.h"
#include "Cr8Icon.h"
#include "SetchelIcon.h"

#include "MC_Info.h"
#include "Tote_Info.h" 
#include "Cr8_Info.h"
#include "Setchel_Info.h"



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

		/*플레이어 정보창 및 캐릭터 스킨들 보여주기*/
		Mc_In();
		Tote_In();
		Cr8_In();
		Setchel_In();


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
		std::stack<UIBase*> tempStack;
		
		//뒤집어서 렌더링을 해준다
		while (!uiBases.empty())
		{
			UIBase* uiBase = uiBases.top();
			tempStack.push(uiBase);
			uiBases.pop();
		}

		while (!tempStack.empty())
		{
			UIBase* uiBase = tempStack.top();
			//tempStack.push(uiBase);
			if (uiBase != nullptr)
			{
				uiBase->Render(hdc);
			}
			tempStack.pop();
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

				uiBase->InActive();
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
		logobutton1->ImageLoad(L"LogoButton1", L"..\\Resources\\Image\\Object\\LogoButton1.bmp");

		LogoButton2* logobutton2 = new LogoButton2(eUIType::LogoButton2);
		mUIs.insert(std::make_pair(eUIType::LogoButton2, logobutton2));
		logobutton2->SetPos(Vector2(620.0f, 530.0f));
		//newUI->SetSize(Vector2(500.0f, 100.0f));
		logobutton2->ImageLoad(L"LogoButton2", L"..\\Resources\\Image\\Object\\LogoButton2.bmp");

		LogoButton3* logobutton3 = new LogoButton3(eUIType::LogoButton3);
		mUIs.insert(std::make_pair(eUIType::LogoButton3, logobutton3));
		logobutton3->SetPos(Vector2(620.0f, 590.0f));
		//newUI->SetSize(Vector2(500.0f, 100.0f));
		logobutton3->ImageLoad(L"LogoButton3", L"..\\Resources\\Image\\Object\\LogoButton3.bmp");

		LogoButton4* logobutton4 = new LogoButton4(eUIType::LogoButton4);
		mUIs.insert(std::make_pair(eUIType::LogoButton4, logobutton4));
		logobutton4->SetPos(Vector2(620.0f, 650.0f));
		//newUI->SetSize(Vector2(500.0f, 100.0f));
		logobutton4->ImageLoad(L"LogoButton4", L"..\\Resources\\Image\\Object\\LogoButton4.bmp");

		LogoButton5* logobutton5 = new LogoButton5(eUIType::LogoButton5);
		mUIs.insert(std::make_pair(eUIType::LogoButton5, logobutton5));
		logobutton5->SetPos(Vector2(620.0f, 710.0f));
		//newUI->SetSize(Vector2(500.0f, 100.0f));
		logobutton5->ImageLoad(L"LogoButton5", L"..\\Resources\\Image\\Object\\LogoButton5.bmp");

		LogoButton6* logobutton6 = new LogoButton6(eUIType::LogoButton6);
		mUIs.insert(std::make_pair(eUIType::LogoButton6, logobutton6));
		logobutton6->SetPos(Vector2(620.0f, 770.0f));
		//newUI->SetSize(Vector2(500.0f, 100.0f));
		logobutton6->ImageLoad(L"LogoButton6", L"..\\Resources\\Image\\Object\\LogoButton6.bmp");
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

		TitleSelectButton1* titleselectbutton1 = new TitleSelectButton1(eUIType::TitleSelectButton1);
		mUIs.insert(std::make_pair(eUIType::TitleSelectButton1, titleselectbutton1));
		titleselectbutton1->SetPos(Vector2(250.0f, 750.0f));
		titleselectbutton1->ImageLoad(L"titleselectbutton1", L"..\\Resources\\Image\\Object\\TitleSelectButton1.bmp");

		TitleSelectButton2* titleselectbutton2 = new TitleSelectButton2(eUIType::TitleSelectButton2);
		mUIs.insert(std::make_pair(eUIType::TitleSelectButton2, titleselectbutton2));
		titleselectbutton2->SetPos(Vector2(650.0f, 750.0f));
		titleselectbutton2->ImageLoad(L"titleselectbutton2", L"..\\Resources\\Image\\Object\\TitleSelectButton2.bmp");


		//
		TitleDefault* titledefault = new TitleDefault(eUIType::TitleDefault);
		mUIs.insert(std::make_pair(eUIType::TitleDefault, titledefault));
		titledefault->ImageLoad(L"TitleDefault", L"..\\Resources\\Image\\Object\\TitleDefault.bmp");
		titledefault->SetPos(Vector2(250.0f, 50.0f));

		titledefault->AddChild(mcicon);
		titledefault->AddChild(toteicon);
		titledefault->AddChild(cr8icon);
		titledefault->AddChild(setchelicon);

		titledefault->AddChild(titleselectbutton1);
		titledefault->AddChild(titleselectbutton2);
		//△패널
		
	}

	void UIManager::Mc_In()
	{
		TitleSelectBg* titleselectbg = new TitleSelectBg(eUIType::TitleSelectBg);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg, titleselectbg));
		titleselectbg->SetPos(Vector2(-20.0f, 420.0f));
		titleselectbg->ImageLoad(L"titleselectbg", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");

		TitleSelectBg2* titleselectbg2 = new TitleSelectBg2(eUIType::TitleSelectBg2);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg2, titleselectbg2));
		titleselectbg2->SetPos(Vector2(180.0f, 420.0f));
		titleselectbg2->ImageLoad(L"titleselectbg2", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");

		TitleSelectBg3* titleselectbg3 = new TitleSelectBg3(eUIType::TitleSelectBg3);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg3, titleselectbg3));
		titleselectbg3->SetPos(Vector2(380.0f, 420.0f));
		titleselectbg3->ImageLoad(L"titleselectbg3", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");

		TitleSelectBg4* titleselectbg4 = new TitleSelectBg4(eUIType::TitleSelectBg4);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg4, titleselectbg4));
		titleselectbg4->SetPos(Vector2(580.0f, 420.0f));
		titleselectbg4->ImageLoad(L"titleselectbg4", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");
		//
		MC_Info* mc_info = new MC_Info(eUIType::Mc_Info);
		mUIs.insert(std::make_pair(eUIType::Mc_Info, mc_info));
		mc_info->SetPos(Vector2(470.0f, 170.0f));
		mc_info->ImageLoad(L"mc_info", L"..\\Resources\\Image\\Object\\MC_Info.bmp");
		mc_info->AddChild(titleselectbg);
		mc_info->AddChild(titleselectbg2);
		mc_info->AddChild(titleselectbg3);
		mc_info->AddChild(titleselectbg4);
		//△패널
	}

	void UIManager::Tote_In()
	{

		TitleSelectBg5* titleselectbg5 = new TitleSelectBg5(eUIType::TitleSelectBg5);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg5, titleselectbg5));
		titleselectbg5->SetPos(Vector2(150.0f, 390.0f));
		titleselectbg5->ImageLoad(L"titleselectbg5", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");

		TitleSelectBg6* titleselectbg6 = new TitleSelectBg6(eUIType::TitleSelectBg6);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg6, titleselectbg6));
		titleselectbg6->SetPos(Vector2(350.0f, 390.0f));
		titleselectbg6->ImageLoad(L"titleselectbg6", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");

		//
		Tote_Info* tote_info = new Tote_Info(eUIType::Tote_Info);
		mUIs.insert(std::make_pair(eUIType::Tote_Info, tote_info));
		tote_info->SetPos(Vector2(500.0f, 200.0f));
		tote_info->ImageLoad(L"tote_info", L"..\\Resources\\Image\\Object\\Tote_Info.bmp");
		tote_info->AddChild(titleselectbg5);
		tote_info->AddChild(titleselectbg6);
		//△패널
	}

	void UIManager::Cr8_In()
	{
		TitleSelectBg7* titleselectbg7 = new TitleSelectBg7(eUIType::TitleSelectBg7);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg7, titleselectbg7));
		titleselectbg7->SetPos(Vector2(250.0f, 380.0f));
		titleselectbg7->ImageLoad(L"titleselectbg7", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");


		//
		Cr8_Info* cr8_info = new Cr8_Info(eUIType::Cr8_Info);
		mUIs.insert(std::make_pair(eUIType::Cr8_Info, cr8_info));
		cr8_info->SetPos(Vector2(500.0f, 200.0f));
		cr8_info->ImageLoad(L"cr8_info", L"..\\Resources\\Image\\Object\\Cr8_Info.bmp");
		cr8_info->AddChild(titleselectbg7);
		//△패널
	}

	void UIManager::Setchel_In()
	{
		TitleSelectBg8* titleselectbg8 = new TitleSelectBg8(eUIType::TitleSelectBg8);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg8, titleselectbg8));
		titleselectbg8->SetPos(Vector2(250.0f, 380.0f));
		titleselectbg8->ImageLoad(L"titleselectbg8", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");

		//
		Setchel_Info* setchel_info = new Setchel_Info(eUIType::Setchel_Info);
		mUIs.insert(std::make_pair(eUIType::Setchel_Info, setchel_info));
		setchel_info->SetPos(Vector2(500.0f, 200.0f));
		setchel_info->ImageLoad(L"setchel_info", L"..\\Resources\\Image\\Object\\Setchel_Info.bmp");
		setchel_info->AddChild(titleselectbg8);
		//△패널
	}

	

}