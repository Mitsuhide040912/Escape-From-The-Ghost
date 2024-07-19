#include "GameOverScene.h"
#include "Engine/SceneManager.h"
#include <assert.h>
GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent,"GameOverScene")
{
	hImage = LoadGraph("Assets/GameOverScene.png");
	assert(hImage > 0);
}

void GameOverScene::Initialize()
{
}

void GameOverScene::Update()
{
	if (CheckHitKey(KEY_INPUT_R))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

void GameOverScene::Draw()
{
	int screenWidth, screenHeight;
	GetScreenState(&screenWidth, &screenHeight, NULL);
	int imgWidth = 1280;
	int imgHeight = 720;
	int x = 0;
	int y = 0;
	DrawExtendGraph(x, y, screenWidth, screenHeight, hImage, TRUE);

}

void GameOverScene::Release()
{
}
