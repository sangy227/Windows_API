#pragma once
#include "Common.h"

namespace ya
{
	//메인 프로그램이 딜 녀석
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

	private:
		Application();
		~Application();

	private:
		WindowData mWindowData;
	};

}

