#pragma once
#include "Common.h"

namespace ya
{
	//¸ÞÀÎ ÇÁ·Î±×·¥ÀÌ µô ³à¼®
	class Application
	{
	public:
		static Application& GetInstance() 
		{
			static Application mInstance;
			return mInstance;
		}

		void Initialize(WindowData data);
		void Tick();

		WindowData GetWindowData() {
			return mWindowData;
		}

	private:
		Application();
		~Application();

		void InitializeWindow(WindowData data);

	private:
		WindowData mWindowData;
		HPEN mPens[(UINT)ePenColor::End];
		HBRUSH mBrushs[(UINT)eBrushColor::End];
	};

}

