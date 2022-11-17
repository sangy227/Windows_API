#pragma once
#include "yaUIBase.h"

namespace ya {

	class Panel : public UIBase
	{
	public:
		Panel();
		~Panel();

		virtual void OnInit() override;
		virtual void OnActive() override;
		virtual void OninActive() override;
		virtual void OnTick() override;
		virtual void OnRender(HDC hdc) override;
		virtual void OnClear() override;

		void AddUIBase(UIBase* uiBase);
	private:
		std::vector<UIBase*> mChilds;
		
	};
}

