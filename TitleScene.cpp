#include "TitleScene.h"
#include "Engine/SceneManager.h"
#include <assert.h>
TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene")
{
	hImage = LoadGraph("Assets/TitleScene.png");
	assert(hImage > 0);
}

void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
	int screenWidth, screenHeight;
	GetScreenState(&screenWidth, &screenHeight, NULL);
	int imgWidth = 1280;
	int imgHeight = 720;
	int x = 0;
	int y = 0;
	DrawExtendGraph(x, y, screenWidth, screenHeight, hImage, TRUE);
}

void TitleScene::Release()
{
}
