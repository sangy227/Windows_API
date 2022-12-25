#pragma once
#include "Common.h"
#include "yaUIBase.h"

namespace ya {
	class UIManager
	{
	public:
		static void Initialize();
		static void OnLoad(eUIType type);
		static void Tick();
		static void Render(HDC hdc);
		static void OnComplete(UIBase* addUI);
		static void OnFail();

		static void Release();

		static void Push(eUIType type);
		static void Pop(eUIType type);

		template <typename T>
		static T* GetUiInstant(eUIType type)
		{
			return dynamic_cast<T*>(mUIs[type]);
		}

		static void LogoButtonFull();

		static void PlayerSelectFull();
		static void Mc_In();
		static void Tote_In();
		static void Cr8_In();
		static void Setchel_In();

		static void PlaySceneUI();
		static void Inventoty_Pull();

		
	private:
		static std::unordered_map <eUIType, UIBase*> mUIs;
		static std::queue<eUIType> mRequestUIQueue;
		static std::stack<UIBase*> mUIBases;
		static UIBase* mCurrentData;

		
	};
}

