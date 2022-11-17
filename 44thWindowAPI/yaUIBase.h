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

		eUIType GetType() { return mType; }
		bool GetIsFullScreen() { return mbFullScreen; }
		void SetIsFullScreen(bool enable) {mbEnable = enable;}
		void SetParent(UIBase* parent) { mParent = parent; }
		void SetPos(Vector2 pos) { mScreenPos = pos; }
		Vector2 GetPos() { return mScreenPos; }
		void SetSize(Vector2 size) { mSize = size; }
		Vector2 GetSize() { return mSize; }

	protected:
		Image* mImage;
		Vector2 mScreenPos;
		Vector2 mPos;
		Vector2 mSize;

	private:
		virtual void OnInit() {};
		virtual void OnActive() {};
		virtual void OninActive() {};
		virtual void OnTick() {};
		virtual void OnRender(HDC hdc) {};
		virtual void OnClear() {};
	

	private:
		UIBase* mParent;
		eUIType mType;
		bool mbFullScreen;
		bool mbEnable;
	};
}

