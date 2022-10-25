#pragma once

#include "Common.h"
#include "yaEntity.h"

namespace ya {
	class GameObject : public Entity
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		void SetPos(Vector2 pos) { mPos = pos; }
		Vector2 GetPos() { return mPos; }
		void SetScale(Vector2 scale) { mScale = scale; }
		Vector2 GetScale() { return mScale; }

		/*void SetHdc(HDC hdc) { mHdc = hdc; }
		HDC GetHdc() {
			return mHdc;
		}*/

	private:
		Vector2 mPos;
		Vector2 mScale;
		//HDC mHdc;

	};
}

