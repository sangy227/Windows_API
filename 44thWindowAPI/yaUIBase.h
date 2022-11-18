#pragma once
#include "yaEntity.h"

namespace ya {
	class Image;
	class UIBase : public Entity
	{
	public:

		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};


		UIBase(eUIType type);
		virtual~UIBase();


		void Initialize();
		void Active();
		void InActive();

		void Tick();
		void Render(HDC hdc);

		void UIClear();

		void ImageLoad(const std::wstring& key, const std::wstring& path);
		void AddChild(UIBase* uiBase);

		eUIType GetType() { return mType; }
		bool GetIsFullScreen() { return mbFullScreen; }
		void SetIsFullScreen(bool enable) {mbEnable = enable;}

		void SetParent(UIBase* parent) { mParent = parent; }
		void SetScreenPos(Vector2 pos) { mScreenPos = pos; }
		void SetPos(Vector2 pos) { mPos = pos; }

		Vector2 GetScreenPos() { return mScreenPos; }
		Vector2 GetPos() { return mPos; }

		void SetSize(Vector2 size) { mSize = size; }
		Vector2 GetSize() { return mSize; }
		
	protected:
		UIBase* mParent;
		Image* mImage;
		Vector2 mPos;
		Vector2 mSize;
		Vector2 mScreenPos;
		

	private:
		virtual void OnInit() {};
		virtual void OnActive() {};
		virtual void OnInActive() {};
		virtual void OnTick() {};
		virtual void OnRender(HDC hdc) {};
		virtual void OnClear() {};
	

	private:
		std::vector<UIBase*> mChilds;
		
		eUIType mType;
		bool mbFullScreen;
		bool mbEnable;

	
	};
}

