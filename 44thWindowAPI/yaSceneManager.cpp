#include "yaSceneManager.h"
#include "yaLogoScene.h"

namespace ya {

	Scene* SceneManager::mScenes[(UINT)eSceneType::Max] = {};
	Scene* SceneManager::mPlayScene = nullptr;

	void SceneManager::Initialize()
	{
		//¸ðµç¾ÀµéÀ» ÃÊ±âÈ­
		mScenes[(UINT)eSceneType::Logo] = new LogoScene();
		mScenes[(UINT)eSceneType::Logo]->Initialize();

		mPlayScene = mScenes[(UINT)eSceneType::Logo];
	}

	void SceneManager::Tick()
	{
		//ÇöÀç ¾ÀµéÀ» update Tick
		mPlayScene->Tick();
	}

	void SceneManager::Render(HDC hdc)
	{
		//ÇöÀç¾À ·»´õ¸µ
		mPlayScene->Render(hdc);
	}

	void SceneManager::Release()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			delete scene;
			scene = nullptr;
		}
	}

}
