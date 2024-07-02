#include "PlayScene.h"
#include "Field.h"
#include "Player.h"
#include "Camera.h"
//#include "Bird.h"
#include "Enemy.h"
#include "BackGround.h"
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent, "PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Camera>(this);
	Instantiate<BackGround>(this);
	//Instantiate<Field>(this);
	Field* pField = Instantiate<Field>(this);
	pField->Reset();
	Instantiate<Enemy>(this);
	Instantiate<Player>(this);
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
