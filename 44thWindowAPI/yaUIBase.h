#pragma once
#include "yaEntity.h"

namespace ya {

	class UIBase : public Entity
	{
	public:
		UIBase(eUIType type);
		virtual~UIBase();


		void Initialize();
		void Active();
		void InActive();

		void Tick();
		void Render(HDC hdc);

		void UIClear();

		virtual void OnInit() {};
		virtual void OnActive() {};
		virtual void OninActive() {};
		virtual void OnTick() {};
		virtual void OnUIClear() {};

		eUIType GetType() { return mType; }
		bool GetIsFullScreen() { return mbFullScreen; }
		void SetIsFullScreen(bool enable) {mbEnable = enable;}
	private:
		eUIType mType;
		bool mbFullScreen;
		bool mbEnable;
	};
}

