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
		//sound = LoadSoundMem("Assets/GB-Action-D10-1(Clear).MP3");
		//assert(sound != -1);
		//PlaySoundMem(sound, DX_PLAYTYPE_BACK); // ‰¹º‚ðÄ¶
		PlaySoundFile("Assets/GB-Action-D10-1(Clear).MP3", DX_PLAYTYPE_BACK);
		// ‰¹—Ê‚ÌÝ’è
		ChangeVolumeSoundMem(255 * 10 / 100, sound);
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_TITLE);
	}	
	//else
	//{
	//	DeleteSoundMem(sound);
	//}

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
