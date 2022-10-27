#pragma once
#include "yaComponent.h"

namespace ya {
	class AniMator:public Component
	{
	public:
		AniMator();
		~AniMator();

		virtual void Tick() override;
		
	private:


	};
}

