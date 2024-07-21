#include "GameClear.h"
#include "Engine/SceneManager.h"
GameClear::GameClear(GameObject* parent)
	:GameObject(parent, "GameClearScene")
{
	hImage = LoadGraph("Assets/GameClearScene.png");
	assert(hImage > 0);
}

void GameClear::Initialize()
{
}

void GameClear::Update()
{
	if (CheckHitKey(KEY_INPUT_R))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
}

void GameClear::Draw()
{
	int screenWidth, screenHeight;
	GetScreenState(&screenWidth, &screenHeight, NULL);
	int imgWidth = 1280;
	int imgHeight = 720;
	int x = 0;
	int y = 0;
	DrawExtendGraph(x, y, screenWidth, screenHeight, hImage, TRUE);
}

void GameClear::Release()
{
}
