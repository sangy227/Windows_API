#pragma once
#include "yaGameObject.h"

namespace ya {
	class Ground : public GameObject
	{
	public:
		Ground();
		~Ground();

		virtual void Tick();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

	private:

	};
}

