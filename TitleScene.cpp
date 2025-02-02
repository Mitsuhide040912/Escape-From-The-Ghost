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
		//sound = LoadSoundMem("Assets/GB-Action-C06-1(Stage5).MP3");
		//assert(sound != -1);
		//PlaySoundMem(sound, DX_PLAYTYPE_BACK); // 音声を再生
		PlaySoundFile("Assets/GB-Action-C06-1(Stage5).MP3", DX_PLAYTYPE_BACK);
		// 音量の設定
		ChangeVolumeSoundMem(255 * 10 / 100, SHandle);
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
	//else
	//{
	//	StopSoundMem(sound);
	//}
	//StopSoundMem(SHandle);
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
