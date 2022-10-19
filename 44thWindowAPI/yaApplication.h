#pragma once
#include "Common.h"

namespace ya
{
	class Application
	{
	public:
		//?이걸 왜하죠
		static Application& GetInstance() {
			return mInstance;
		}

		Application();
		~Application();

		void Initialize(WindowData data);
		void Tick();


	private:
		static Application mInstance;
		WindowData mWindowData;
	};

}

