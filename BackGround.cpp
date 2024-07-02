#include "BackGround.h"
#include <DxLib.h>
#include <assert.h>
BackGround::BackGround(GameObject* scene)
{

	hImage = LoadGraph("Assets/GhostMap.png");
	assert(hImage > 0);

}

BackGround::~BackGround()
{
}

void BackGround::Update()
{

}

void BackGround::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	LoadGraphScreen(0, 0, "Assets/GhostMap.png", TRUE);

	DrawExtendGraph(x, y, 1370, 1000, hImage, TRUE);
}

