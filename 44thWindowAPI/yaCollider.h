#pragma once
#include "yaComponent.h"

namespace ya
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		void SetScale(Vector2 scale) { mScale = scale; }
		void SetmPos(Vector2 Pos) { mPos = Pos; }
		void SetmmOffset(Vector2 mPos) { mOffset = mPos; }

		Vector2 GetPos() { return mPos; }
		Vector2 GetOffset() { return mOffset; }
		Vector2 GetScale() { return mScale; }

	private:
		Vector2 mOffset;
		Vector2 mPos;
		Vector2 mScale;

	};
}
