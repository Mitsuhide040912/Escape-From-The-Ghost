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
	if (CheckHitKey(KEY_INPUT_T))
	{
		//sound = LoadSoundMem("Assets/GB-Action-D10-1(Clear).MP3");
		//assert(sound != -1);
		//PlaySoundMem(sound, DX_PLAYTYPE_BACK); // 音声を再生
		PlaySoundFile("Assets/GB-Action-D10-1(Clear).MP3", DX_PLAYTYPE_BACK);
		// 音量の設定
		ChangeVolumeSoundMem(255 * 10 / 100, sound);
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}
	//else
	//{
	//	StopSoundMem(sound);
	//}
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
