#pragma once
#include "Common.h"


namespace ya {
	class Scene;
	class SceneManager
	{
	public:

		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
		static void DetroyGameObject();
		static void Release();

		static void ChangeScene(eSceneType type);

		static Scene* GetPlayScene() { return mPlayScene; } 
		static eSceneType GetPlaySceneType() { return mType; }
		
		static void   SetPlayScene(Scene* playScene) { mPlayScene = playScene; }


	private:
		static Scene* mScenes[(UINT)eSceneType::Max];
		static Scene* mPlayScene;
		static eSceneType mType;
	};
}

