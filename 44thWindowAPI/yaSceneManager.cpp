#include "yaSceneManager.h"
#include "yaLogoScene.h"
#include "yaTitleScene.h"
#include "yaPlayScene.h"
#include "yaEndScene.h"
#include "yaObject.h"
#include "yaPlayScene2.h"
#include "yaPlayScene3.h"
#include "yaPlayScene4.h"
#include "yaToolScene.h"

namespace ya {

	Scene* SceneManager::mScenes[(UINT)eSceneType::Max] = {};
	Scene* SceneManager::mPlayScene = nullptr;
	eSceneType SceneManager::mType = eSceneType::Max;


	void SceneManager::Initialize()
	{
		
		//¸ğµç¾ÀµéÀ» ÃÊ±âÈ­
		mScenes[(UINT)eSceneType::Logo] = new LogoScene();
		mScenes[(UINT)eSceneType::Logo]->Initialize();

		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Title]->Initialize();

		mScenes[(UINT)eSceneType::PlayOne] = new PlayScene();
		mScenes[(UINT)eSceneType::PlayOne]->Initialize();

		mScenes[(UINT)eSceneType::PlayTwo] = new PlayScene2();
		mScenes[(UINT)eSceneType::PlayTwo]->Initialize();

		mScenes[(UINT)eSceneType::PlayThree] = new PlayScene3();
		mScenes[(UINT)eSceneType::PlayThree]->Initialize();

		mScenes[(UINT)eSceneType::PlayFour] = new PlayScene4();
		mScenes[(UINT)eSceneType::PlayFour]->Initialize();

		mScenes[(UINT)eSceneType::End] = new EndScene();
		mScenes[(UINT)eSceneType::End]->Initialize();

		mScenes[(UINT)eSceneType::Tool] = new ToolScene();
		mScenes[(UINT)eSceneType::Tool]->Initialize();
		


		ChangeScene(eSceneType::Tool);


		//mPlayScene = mScenes[(UINT)eSceneType::Logo];
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

	void SceneManager::DetroyGameObject()
	{
		ya::object::Release();
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

	void SceneManager::ChangeScene(eSceneType type)
	{
		/*if (mPlayScene == nullptr)
		{
			mPlayScene = mScenes[(UINT)eSceneType::Logo];
		}*/


		if (mScenes[(UINT)type] == nullptr)
			return;

		mType = type;
		
		mPlayScene->Exit();
		mPlayScene = mScenes[(UINT)type];
		
		mPlayScene->Enter();
	}

}
