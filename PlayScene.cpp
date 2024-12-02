#include "PlayScene.h"
#include "Field.h"
#include "Player.h"
#include "Camera.h"
#include "Enemy.h"
//#include "Bullet.h"
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	//Instantiate<BackGround>(this);
	Instantiate<Camera>(this);
	
	//Instantiate<Field>(this);
	Field* pField = Instantiate<Field>(this);
	pField->Reset();
	Instantiate<Player>(this);
	Instantiate<Enemy>(this);
	//Instantiate<Bullet>(this);
	
}

void PlayScene::Update()
{
	//InitSoundMem();
	//DeleteSoundMem(sound);
	//StopSoundMem(SHandle);
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
