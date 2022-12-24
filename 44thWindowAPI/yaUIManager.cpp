#include "yaUIManager.h"
#include "yaHUD.h"
#include "yaButton.h"
#include "yaPanel.h"
#include "yaPlayer.h"
#include "yaUIGameObject.h"
/*ㅡㅡㅡㅡㅡㅡㅡ▼로고씬ㅡㅡㅡㅡㅡㅡㅡㅡ*/
#include "LogoButton1.h"
#include "LogoButton2.h"
#include "LogoButton3.h"
#include "LogoButton4.h"
#include "LogoButton5.h"
#include "LogoButton6.h"

#include "TitleDefault.h"
#include "TitleSelectBg.h"
#include "TitleSelectPlayer.h"
#include "TitleSelectBg2.h"
#include "TitleSelectPlayer2.h"
#include "TitleSelectBg3.h"
#include "TitleSelectPlayer3.h"
#include "TitleSelectBg4.h"
#include "TitleSelectPlayer4.h"

#include "TitleSelectBg5.h"
#include "TitleSelectPlayer5.h"
#include "TitleSelectBg6.h"
#include "TitleSelectPlayer6.h"

#include "TitleSelectBg7.h"
#include "TitleSelectPlayer7.h"

#include "TitleSelectBg8.h"
#include "TitleSelectPlayer8.h"

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
/*ㅡㅡㅡㅡㅡㅡㅡ▼플레이씬ㅡㅡㅡㅡㅡㅡㅡㅡ*/
#include "TopLayerDefault.h"
#include "Stats_Icon.h"
#include "Save_Icon.h"
#include "Option_Icon.h"
#include "Map_Icon.h"
#include "Enemie_icon01.h"
#include "Book_Icon.h"
#include "Back_Icon.h"

#include "Inventory.h"
#include "Map_bg.h"
#include "Map_Gate.h"
#include "Enter_Button.h"
#include "TestButton.h"
#include "UIItem.h"
#include "Item_include.h"
/*ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ*/



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

		/*플레이씬 UI모음*/
		PlaySceneUI();


		//인벤토리 Panel 자식들로 내림
		/*TestButton* testbutton = new TestButton(eUIType::TestButton);
		mUIs.insert(std::make_pair(eUIType::TestButton, testbutton));
		//470 , 122 로 좌표해야 인벤토리 한칸 안에 딱맞음
		testbutton->SetPos(Vector2(470.0f, 122.0f));
		testbutton->ImageLoad(L"testbutton", L"..\\Resources\\Image\\TestButton.bmp");

		TestSword* testsword = new TestSword(eUIType::TestSword);
		mUIs.insert(std::make_pair(eUIType::TestSword, testsword));
		testsword->SetPos(Vector2(550.0f, 120.0f));
		testsword->ImageLoad(L"testsword", L"..\\Resources\\Image\\Sword_of_Venom.bmp"); */
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
		addUI->Tick();
		addUI->Active();

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
		TitleSelectPlayer* titleselectplayer = new TitleSelectPlayer();
		TitleSelectPlayer2* titleselectplayer2 = new TitleSelectPlayer2();
		TitleSelectPlayer3* titleselectplayer3 = new TitleSelectPlayer3();
		TitleSelectPlayer4* titleselectplayer4 = new TitleSelectPlayer4();


		TitleSelectBg* titleselectbg = new TitleSelectBg(eUIType::TitleSelectBg);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg, titleselectbg));
		titleselectbg->SetPos(Vector2(-20.0f, 420.0f));
		titleselectbg->ImageLoad(L"titleselectbg", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");
		titleselectbg->AddGameObject(titleselectplayer); 

		TitleSelectBg2* titleselectbg2 = new TitleSelectBg2(eUIType::TitleSelectBg2);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg2, titleselectbg2));
		titleselectbg2->SetPos(Vector2(180.0f, 420.0f));
		titleselectbg2->ImageLoad(L"titleselectbg2", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");
		titleselectbg2->AddGameObject(titleselectplayer2);

		TitleSelectBg3* titleselectbg3 = new TitleSelectBg3(eUIType::TitleSelectBg3);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg3, titleselectbg3));
		titleselectbg3->SetPos(Vector2(380.0f, 420.0f));
		titleselectbg3->ImageLoad(L"titleselectbg3", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");
		titleselectbg3->AddGameObject(titleselectplayer3);


		TitleSelectBg4* titleselectbg4 = new TitleSelectBg4(eUIType::TitleSelectBg4);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg4, titleselectbg4));
		titleselectbg4->SetPos(Vector2(580.0f, 420.0f));
		titleselectbg4->ImageLoad(L"titleselectbg4", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");
		titleselectbg4->AddGameObject(titleselectplayer4);


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
		TitleSelectPlayer5* titleselectplayer5 = new TitleSelectPlayer5();
		TitleSelectPlayer6* titleselectplayer6 = new TitleSelectPlayer6();


		TitleSelectBg5* titleselectbg5 = new TitleSelectBg5(eUIType::TitleSelectBg5);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg5, titleselectbg5));
		titleselectbg5->SetPos(Vector2(190.0f, 410.0f));
		titleselectbg5->ImageLoad(L"titleselectbg5", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");
		titleselectbg5->AddGameObject(titleselectplayer5);


		TitleSelectBg6* titleselectbg6 = new TitleSelectBg6(eUIType::TitleSelectBg6);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg6, titleselectbg6));
		titleselectbg6->SetPos(Vector2(390.0f, 410.0f));
		titleselectbg6->ImageLoad(L"titleselectbg6", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");
		titleselectbg6->AddGameObject(titleselectplayer6);

		//
		Tote_Info* tote_info = new Tote_Info(eUIType::Tote_Info);
		mUIs.insert(std::make_pair(eUIType::Tote_Info, tote_info));
		tote_info->SetPos(Vector2(460.0f, 180.0f));
		tote_info->ImageLoad(L"tote_info", L"..\\Resources\\Image\\Object\\Tote_Info.bmp");
		tote_info->AddChild(titleselectbg5);
		tote_info->AddChild(titleselectbg6);
		//△패널
	}

	void UIManager::Cr8_In()
	{
		TitleSelectPlayer7* titleselectplayer7 = new TitleSelectPlayer7();


		TitleSelectBg7* titleselectbg7 = new TitleSelectBg7(eUIType::TitleSelectBg7);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg7, titleselectbg7));
		titleselectbg7->SetPos(Vector2(290.0f, 410.0f));
		titleselectbg7->ImageLoad(L"titleselectbg7", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");
		titleselectbg7->AddGameObject(titleselectplayer7);

		//
		Cr8_Info* cr8_info = new Cr8_Info(eUIType::Cr8_Info);
		mUIs.insert(std::make_pair(eUIType::Cr8_Info, cr8_info));
		cr8_info->SetPos(Vector2(460.0f, 180.0f));
		cr8_info->ImageLoad(L"cr8_info", L"..\\Resources\\Image\\Object\\Cr8_Info.bmp");
		cr8_info->AddChild(titleselectbg7);
		//△패널
	}

	void UIManager::Setchel_In()
	{
		TitleSelectPlayer8* titleselectplayer8 = new TitleSelectPlayer8();

		TitleSelectBg8* titleselectbg8 = new TitleSelectBg8(eUIType::TitleSelectBg8);
		mUIs.insert(std::make_pair(eUIType::TitleSelectBg8, titleselectbg8));
		titleselectbg8->SetPos(Vector2(290.0f, 410.0f));
		titleselectbg8->ImageLoad(L"titleselectbg8", L"..\\Resources\\Image\\Object\\TitleSelectBg.bmp");
		titleselectbg8->AddGameObject(titleselectplayer8);

		//
		Setchel_Info* setchel_info = new Setchel_Info(eUIType::Setchel_Info);
		mUIs.insert(std::make_pair(eUIType::Setchel_Info, setchel_info));
		setchel_info->SetPos(Vector2(460.0f, 180.0f));
		setchel_info->ImageLoad(L"setchel_info", L"..\\Resources\\Image\\Object\\Setchel_Info.bmp");
		setchel_info->AddChild(titleselectbg8);
		//△패널
	}

	void UIManager::PlaySceneUI()
	{
		Stats_Icon* stats_icon = new Stats_Icon(eUIType::Stats_Icon);
		mUIs.insert(std::make_pair(eUIType::Stats_Icon, stats_icon));
		stats_icon->SetPos(Vector2(1170.0f, 0.0f));
		stats_icon->ImageLoad(L"stats_icon", L"..\\Resources\\Image\\Object\\Stats_Icon.bmp");

		Save_Icon* save_icon = new Save_Icon(eUIType::Save_Icon);
		mUIs.insert(std::make_pair(eUIType::Save_Icon, save_icon));
		save_icon->SetPos(Vector2(1293.0f, 0.0f));
		save_icon->ImageLoad(L"save_icon", L"..\\Resources\\Image\\Object\\Save_Icon.bmp");

		Option_Icon* option_icon = new Option_Icon(eUIType::Option_Icon);
		mUIs.insert(std::make_pair(eUIType::Stats_Icon, option_icon));
		option_icon->SetPos(Vector2(1468.0f, 0.0f));
		option_icon->ImageLoad(L"option_icon", L"..\\Resources\\Image\\Object\\Option_Icon.bmp");

		Book_Icon* book_icon = new Book_Icon(eUIType::Book_Icon);
		mUIs.insert(std::make_pair(eUIType::Book_Icon, book_icon));
		book_icon->SetPos(Vector2(1130.0f, 0.0f));
		book_icon->ImageLoad(L"book_icon", L"..\\Resources\\Image\\Object\\Book_Icon.bmp");


		//
		TopLayerDefault* toplayerdefault = new TopLayerDefault(eUIType::TopLayerDefault);
		mUIs.insert(std::make_pair(eUIType::TopLayerDefault, toplayerdefault));
		toplayerdefault->SetPos(Vector2(0.0f, 0.0f));
		toplayerdefault->ImageLoad(L"toplayerdefault", L"..\\Resources\\Image\\Object\\TopLayerDefault.bmp");
		toplayerdefault->AddChild(stats_icon);
		toplayerdefault->AddChild(save_icon);
		toplayerdefault->AddChild(option_icon);
		toplayerdefault->AddChild(book_icon);
		//△패널

		Map_Icon* map_icon = new Map_Icon(eUIType::Map_Icon);
		mUIs.insert(std::make_pair(eUIType::Map_Icon, map_icon));
		map_icon->SetPos(Vector2(1518.0f, 72.0f));
		map_icon->ImageLoad(L"Map_Icon", L"..\\Resources\\Image\\Object\\Map_Icon.bmp");
		//△패널 && 버튼

		Back_Icon* back_icon = new Back_Icon(eUIType::Back_Icon);
		mUIs.insert(std::make_pair(eUIType::Back_Icon, back_icon));
		back_icon->SetPos(Vector2(1518.0f, 144.0f));
		back_icon->ImageLoad(L"back_icon", L"..\\Resources\\Image\\Object\\Back_Icon.bmp");
		//△패널 && 버튼


		Inventoty_Pull();
		//△패널 && 버튼

		//Enemie_icon01
		Enemie_icon01* enemie_icon01 = new Enemie_icon01(eUIType::Enemie_icon01);
		mUIs.insert(std::make_pair(eUIType::Enemie_icon01, enemie_icon01));
		enemie_icon01->SetPos(Vector2(480.0f, 70.0f));
		enemie_icon01->ImageLoad(L"enemie_icon01", L"..\\Resources\\Image\\Object\\Enemie_icon.bmp");

		//Map_Gate
		Map_Gate* map_gate = new Map_Gate(eUIType::Map_Gate);
		mUIs.insert(std::make_pair(eUIType::Map_Gate, map_gate));
		map_gate->SetPos(Vector2(450.0f, 50.0f));
		map_gate->ImageLoad(L"map_gate", L"..\\Resources\\Image\\Object\\map_gate.bmp");

		Map_bg* map_bg = new Map_bg(eUIType::Map_bg);
		mUIs.insert(std::make_pair(eUIType::Map_bg, map_bg));
		map_bg->SetPos(Vector2(150.0f, 37.0f));
		map_bg->ImageLoad(L"map_bg", L"..\\Resources\\Image\\Object\\map_bg.bmp");
		map_bg->AddChild(map_gate);
		map_bg->AddChild(enemie_icon01);
		//△패널 && 버튼
	}

	void UIManager::Inventoty_Pull()
	{
		//인벤토리 잠금 모자이크 패턴 들
		//TestButton* testbutton[46] = {};
		//for (size_t i = 0; i < 46; i++)
		//{
		//	testbutton[i] = new TestButton(eUIType::TestButton);
		//	mUIs.insert(std::make_pair(eUIType::TestButton, testbutton[i]));
		//	//460.0f, 160.0f 로 좌표해야 인벤토리 한칸 안에 딱맞음
		//	//testbutton[i]->SetPos(Vector2(460.0f, 160.0f));
		//	testbutton[i]->ImageLoad(L"testbutton", L"..\\Resources\\Image\\blackLayer.bmp");
		//}
		//
		//int black_layer_count = 0;
		//for (int y = 16; y <= 324; y += 77)
		//{
		//	for (int z = 163; z <= 933; z += 77)
		//	{
		//		if ((z == 471 && y == 93) || (z == 548 && y == 93) || (z == 625 && y == 93))
		//			continue;
		//		if ((z == 471 && y == 170) || (z == 548 && y == 170) || (z == 625 && y == 170))
		//			continue;
		//		if ((z == 471 && y == 247) || (z == 548 && y == 247) || (z == 625 && y == 247))
		//			continue;

		//		testbutton[black_layer_count]->SetPos(Vector2(z, y));
		//		black_layer_count++;
		//	}
		//}

		Enter_Button* enter_button = new Enter_Button(eUIType::Enter_Button);
		mUIs.insert(std::make_pair(eUIType::Enter_Button, enter_button));
		enter_button->SetPos(Vector2(1200.0f, 350.0f));
		enter_button->ImageLoad(L"enter_button", L"..\\Resources\\Image\\Object\\Enter_Button.bmp");









		Sword* sword = new Sword(eUIType::TestSword);
		mUIs.insert(std::make_pair(eUIType::TestSword, sword));
		sword->SetPos(Vector2(542.0f, 90.0f));
		sword->ImageLoad(L"sword", L"..\\Resources\\Image\\Sword_of_Venom.bmp");

		Weapon01* weapon01 = new Weapon01(eUIType::Weapon01);
		mUIs.insert(std::make_pair(eUIType::Weapon01, weapon01));
		weapon01->SetPos(Vector2(619.0f, 90.0f));
		weapon01->ImageLoad(L"weapon01", L"..\\Resources\\Image\\item\\Weapon\\Weapon01.bmp");

		Weapon02* weapon02 = new Weapon02(eUIType::Weapon02);
		mUIs.insert(std::make_pair(eUIType::Weapon02, weapon02));
		weapon02->SetPos(Vector2(450.0f, 90.0f));
		weapon02->ImageLoad(L"weapon02", L"..\\Resources\\Image\\item\\Weapon\\Weapon02.bmp");

		Weapon03* weapon03 = new Weapon03(eUIType::Weapon03);
		mUIs.insert(std::make_pair(eUIType::Weapon03, weapon03));
		weapon03->SetPos(Vector2(370.0f, 90.0f));
		weapon03->ImageLoad(L"weapon03", L"..\\Resources\\Image\\item\\Weapon\\Weapon03.bmp");

		Weapon04* weapon04 = new Weapon04(eUIType::Weapon04);
		mUIs.insert(std::make_pair(eUIType::Weapon04, weapon04));
		weapon04->SetPos(Vector2(690.0f, 90.0f));
		weapon04->ImageLoad(L"weapon04", L"..\\Resources\\Image\\item\\Weapon\\Weapon04.bmp");

		Weapon05* weapon05 = new Weapon05(eUIType::Weapon05);
		mUIs.insert(std::make_pair(eUIType::Weapon05, weapon05));
		weapon05->SetPos(Vector2(370.0f, 170.0f));
		weapon05->ImageLoad(L"weapon05", L"..\\Resources\\Image\\item\\Weapon\\Weapon05.bmp");


		Shield01* shield01 = new Shield01(eUIType::Shield01);
		mUIs.insert(std::make_pair(eUIType::Shield01, shield01));
		shield01->SetPos(Vector2(10.0f, 10.0f));
		shield01->ImageLoad(L"shield01", L"..\\Resources\\Image\\item\\Shield\\Shield01.bmp");

		Shield02* shield02 = new Shield02(eUIType::Shield02);
		mUIs.insert(std::make_pair(eUIType::Shield02, shield02));
		shield02->SetPos(Vector2(10.0f, 10.0f));
		shield02->ImageLoad(L"shield02", L"..\\Resources\\Image\\item\\Shield\\Shield02.bmp");

		Shield03* shield03 = new Shield03(eUIType::Shield03);
		mUIs.insert(std::make_pair(eUIType::Shield03, shield03));
		shield03->SetPos(Vector2(10.0f, 10.0f));
		shield03->ImageLoad(L"shield03", L"..\\Resources\\Image\\item\\Shield\\Shield03.bmp");

		Shield04* shield04 = new Shield04(eUIType::Shield04);
		mUIs.insert(std::make_pair(eUIType::Shield04, shield04));
		shield04->SetPos(Vector2(10.0f, 10.0f));
		shield04->ImageLoad(L"shield04", L"..\\Resources\\Image\\item\\Shield\\Shield04.bmp");

		Shield05* shield05 = new Shield05(eUIType::Shield05);
		mUIs.insert(std::make_pair(eUIType::Shield05, shield05));
		shield05->SetPos(Vector2(10.0f, 10.0f));
		shield05->ImageLoad(L"shield05", L"..\\Resources\\Image\\item\\Shield\\Shield05.bmp");

	
		Potion01* potion01 = new Potion01(eUIType::Potion01);
		mUIs.insert(std::make_pair(eUIType::Potion01, potion01));
		potion01->SetPos(Vector2(10.0f, 80.0f));
		potion01->ImageLoad(L"potion01", L"..\\Resources\\Image\\item\\Potion\\Potion01.bmp");

		Potion02* potion02 = new Potion02(eUIType::Potion02);
		mUIs.insert(std::make_pair(eUIType::Potion02, potion02));
		potion02->SetPos(Vector2(10.0f, 80.0f));
		potion02->ImageLoad(L"potion02", L"..\\Resources\\Image\\item\\Potion\\Potion02.bmp");

		Potion03* potion03 = new Potion03(eUIType::Potion03);
		mUIs.insert(std::make_pair(eUIType::Potion03, potion03));
		potion03->SetPos(Vector2(10.0f, 80.0f));
		potion03->ImageLoad(L"potion03", L"..\\Resources\\Image\\item\\Potion\\Potion03.bmp");

		Potion04* potion04 = new Potion04(eUIType::Potion04);
		mUIs.insert(std::make_pair(eUIType::Potion04, potion04));
		potion04->SetPos(Vector2(10.0f, 80.0f));
		potion04->ImageLoad(L"potion04", L"..\\Resources\\Image\\item\\Potion\\Potion04.bmp");

		Potion05* potion05 = new Potion05(eUIType::Potion05);
		mUIs.insert(std::make_pair(eUIType::Potion05, potion05));
		potion05->SetPos(Vector2(10.0f, 80.0f));
		potion05->ImageLoad(L"potion05", L"..\\Resources\\Image\\item\\Potion\\Potion05.bmp");

		Potion06* potion06 = new Potion06(eUIType::Potion06);
		mUIs.insert(std::make_pair(eUIType::Potion06, potion06));
		potion06->SetPos(Vector2(10.0f, 80.0f));
		potion06->ImageLoad(L"potion06", L"..\\Resources\\Image\\item\\Potion\\Potion06.bmp");

		Potion07* potion07 = new Potion07(eUIType::Potion07);
		mUIs.insert(std::make_pair(eUIType::Potion07, potion07));
		potion07->SetPos(Vector2(10.0f, 80.0f));
		potion07->ImageLoad(L"potion07", L"..\\Resources\\Image\\item\\Potion\\Potion07.bmp");

		Potion08* potion08 = new Potion08(eUIType::Potion08);
		mUIs.insert(std::make_pair(eUIType::Potion08, potion08));
		potion08->SetPos(Vector2(10.0f, 80.0f));
		potion08->ImageLoad(L"potion08", L"..\\Resources\\Image\\item\\Potion\\Potion08.bmp");

		Potion09* potion09 = new Potion09(eUIType::Potion09);
		mUIs.insert(std::make_pair(eUIType::Potion09, potion09));
		potion09->SetPos(Vector2(10.0f, 80.0f));
		potion09->ImageLoad(L"potion09", L"..\\Resources\\Image\\item\\Potion\\Potion09.bmp");

		Potion10* potion10 = new Potion10(eUIType::Potion10);
		mUIs.insert(std::make_pair(eUIType::Potion10, potion10));
		potion10->SetPos(Vector2(10.0f, 80.0f));
		potion10->ImageLoad(L"potion10", L"..\\Resources\\Image\\item\\Potion\\Potion10.bmp");

		Potion11* potion11 = new Potion11(eUIType::Potion11);
		mUIs.insert(std::make_pair(eUIType::Potion11, potion11));
		potion11->SetPos(Vector2(10.0f, 80.0f));
		potion11->ImageLoad(L"potion11", L"..\\Resources\\Image\\item\\Potion\\Potion11.bmp");

		Potion12* potion12 = new Potion12(eUIType::Potion12);
		mUIs.insert(std::make_pair(eUIType::Potion12, potion12));
		potion12->SetPos(Vector2(10.0f, 80.0f));
		potion12->ImageLoad(L"potion12", L"..\\Resources\\Image\\item\\Potion\\Potion12.bmp");



		Jewelry01* jewelry01 = new Jewelry01(eUIType::Jewelry01);
		mUIs.insert(std::make_pair(eUIType::Jewelry01, jewelry01));
		jewelry01->SetPos(Vector2(10.0f, 150.0f));
		jewelry01->ImageLoad(L"jewelry01", L"..\\Resources\\Image\\item\\Jewelry\\Jewelry01.bmp");

		Jewelry02* jewelry02 = new Jewelry02(eUIType::Jewelry02);
		mUIs.insert(std::make_pair(eUIType::Jewelry02, jewelry02));
		jewelry02->SetPos(Vector2(10.0f, 150.0f));
		jewelry02->ImageLoad(L"jewelry02", L"..\\Resources\\Image\\item\\Jewelry\\Jewelry02.bmp");

		Jewelry03* jewelry03 = new Jewelry03(eUIType::Jewelry03);
		mUIs.insert(std::make_pair(eUIType::Jewelry03, jewelry03));
		jewelry03->SetPos(Vector2(10.0f, 150.0f));
		jewelry03->ImageLoad(L"jewelry03", L"..\\Resources\\Image\\item\\Jewelry\\Jewelry03.bmp");


		//Dagger
		Dagger01* dagger01 = new Dagger01(eUIType::Dagger01);
		mUIs.insert(std::make_pair(eUIType::Dagger01, dagger01));
		dagger01->SetPos(Vector2(10.0f, 220.0f));
		dagger01->ImageLoad(L"dagger01", L"..\\Resources\\Image\\item\\Dagger\\Dagger01.bmp");

		Dagger02* dagger02 = new Dagger02(eUIType::Dagger02);
		mUIs.insert(std::make_pair(eUIType::Dagger02, dagger02));
		dagger02->SetPos(Vector2(10.0f, 220.0f));
		dagger02->ImageLoad(L"dagger02", L"..\\Resources\\Image\\item\\Dagger\\Dagger02.bmp");

		Dagger03* dagger03 = new Dagger03(eUIType::Dagger03);
		mUIs.insert(std::make_pair(eUIType::Dagger03, dagger03));
		dagger03->SetPos(Vector2(10.0f, 220.0f));
		dagger03->ImageLoad(L"dagger03", L"..\\Resources\\Image\\item\\Dagger\\Dagger03.bmp");

		Dagger04* dagger04 = new Dagger04(eUIType::Dagger04);
		mUIs.insert(std::make_pair(eUIType::Dagger04, dagger04));
		dagger04->SetPos(Vector2(10.0f, 220.0f));
		dagger04->ImageLoad(L"dagger04", L"..\\Resources\\Image\\item\\Dagger\\Dagger04.bmp");

		Dagger05* dagger05 = new Dagger05(eUIType::Dagger05);
		mUIs.insert(std::make_pair(eUIType::Dagger05, dagger05));
		dagger05->SetPos(Vector2(10.0f, 220.0f));
		dagger05->ImageLoad(L"dagger05", L"..\\Resources\\Image\\item\\Dagger\\Dagger05.bmp");


		//Bow01
		Bow01* bow01 = new Bow01(eUIType::Bow01);
		mUIs.insert(std::make_pair(eUIType::Bow01, bow01));
		bow01->SetPos(Vector2(300.0f, 80.0f));
		bow01->ImageLoad(L"bow01", L"..\\Resources\\Image\\item\\Bow_Arrow\\Bow01.bmp");

		Bow02* bow02 = new Bow02(eUIType::Bow02);
		mUIs.insert(std::make_pair(eUIType::Bow02, bow02));
		bow02->SetPos(Vector2(300.0f, 80.0f));
		bow02->ImageLoad(L"bow02", L"..\\Resources\\Image\\item\\Bow_Arrow\\Bow02.bmp");

		Bow03* bow03 = new Bow03(eUIType::Bow03);
		mUIs.insert(std::make_pair(eUIType::Bow03, bow03));
		bow03->SetPos(Vector2(300.0f, 80.0f));
		bow03->ImageLoad(L"bow03", L"..\\Resources\\Image\\item\\Bow_Arrow\\Bow03.bmp");

		//Arrow01
		Arrow01* arrow01 = new Arrow01(eUIType::Arrow01);
		mUIs.insert(std::make_pair(eUIType::Arrow01, arrow01));
		arrow01->SetPos(Vector2(300.0f, 80.0f));
		arrow01->ImageLoad(L"arrow01", L"..\\Resources\\Image\\item\\Bow_Arrow\\Arrow01.bmp");

		Arrow02* arrow02 = new Arrow02(eUIType::Arrow02);
		mUIs.insert(std::make_pair(eUIType::Arrow02, arrow02));
		arrow02->SetPos(Vector2(300.0f, 80.0f));
		arrow02->ImageLoad(L"arrow02", L"..\\Resources\\Image\\item\\Bow_Arrow\\Arrow02.bmp");

		Arrow03* arrow03 = new Arrow03(eUIType::Arrow03);
		mUIs.insert(std::make_pair(eUIType::Arrow03, arrow03));
		arrow03->SetPos(Vector2(300.0f, 80.0f));
		arrow03->ImageLoad(L"arrow03", L"..\\Resources\\Image\\item\\Bow_Arrow\\Arrow03.bmp");


		Inventory* inventory = new Inventory(eUIType::Inventory2);
		mUIs.insert(std::make_pair(eUIType::Inventory2, inventory));
		inventory->SetPos(Vector2(240.0f, 37.0f));
		inventory->ImageLoad(L"inventory", L"..\\Resources\\Image\\Object\\Inventory.bmp");
		//인벤토리-자식들
		/*for (size_t i = 0; i < 46; i++)
			inventory->AddChild(testbutton[i]);*/

		inventory->AddChild(weapon01);
		inventory->AddChild(weapon02);
		inventory->AddChild(weapon03);
		inventory->AddChild(weapon04);
		inventory->AddChild(weapon05);

		inventory->AddChild(shield01);
		inventory->AddChild(shield02);
		inventory->AddChild(shield03);
		inventory->AddChild(shield04);
		inventory->AddChild(shield05);

		inventory->AddChild(potion01);
		inventory->AddChild(potion02);
		inventory->AddChild(potion03);
		inventory->AddChild(potion04);
		inventory->AddChild(potion05);
		inventory->AddChild(potion06);
		inventory->AddChild(potion07);
		inventory->AddChild(potion08);
		inventory->AddChild(potion09);
		inventory->AddChild(potion10);
		inventory->AddChild(potion11);
		inventory->AddChild(potion12);

		inventory->AddChild(jewelry01);
		inventory->AddChild(jewelry02);
		inventory->AddChild(jewelry03);
		
		inventory->AddChild(dagger01);
		inventory->AddChild(dagger02);
		inventory->AddChild(dagger03);

		inventory->AddChild(bow01);
		inventory->AddChild(bow02);
		inventory->AddChild(bow03);

		inventory->AddChild(arrow01);
		inventory->AddChild(arrow02);
		inventory->AddChild(arrow03);

		
		inventory->AddChild(sword);
		inventory->AddChild(enter_button);
	}

	

	

}