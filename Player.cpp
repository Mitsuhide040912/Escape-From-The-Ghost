#include "Player.h"
#include "Camera.h"
#include <DxLib.h>
#include <assert.h>
#include "Field.h"
#include "Enemy.h"
#include "Bullet.h"
#include "thorn.h"
#include "Engine//SceneManager.h"
namespace
{
	float MOVE_SPEED = 2.5f;
	float GRUVITY = 9.0f / 60.0f; //重力
	float GROUND = 300.0f;
	float JUMP_HEIGHT = 60.0f * 2.0f;//ジャンプの高さ

}
Player::Player(GameObject* scene)
{
	hImage = LoadGraph("Assets/PikoC-Girl01.png");
	assert(hImage > 0);
	transform_.position_.x = 3000.0f;
	transform_.position_.y = GROUND;
	//canjump = false;
	onground = true;
}

Player::~Player()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void Player::Update()
{
	Field* pField = GetParent()->FindGameObject<Field>();
	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		transform_.position_.x += MOVE_SPEED;
		if (++FrameCounter >= 8) {
			animFrame = (animFrame + 1) % 4;
			FrameCounter = 0;
		}
		int hitX = transform_.position_.x + 50;
		int hitY = transform_.position_.y + 60;
		if (pField != nullptr){
			int push = pField->CollisionRight(hitX, hitY);
			transform_.position_.x -= push;
		}
	}
	else if (CheckHitKey(KEY_INPUT_LEFT))
	{
		transform_.position_.x -= MOVE_SPEED;
		if (++FrameCounter >= 8) {
			animFrame = (animFrame + 1) % 4;
			FrameCounter = 0;
		}
		int hitX = transform_.position_.x + 25;
		int hitY = transform_.position_.y + 40;
		if (pField != nullptr){
			int push = pField->CollisionLeft(hitX, hitY);
			transform_.position_.x += push;
		}
	}
	else
	{
		FrameCounter = 0;
		animFrame = 0;
	}

	//↓プレイヤーが強制スクロールについていくための処理
	//transform_.position_.x += MOVE_SPEED;
	
   /* canjump = true;*/
	
	//if (CheckHitKey(KEY_INPUT_SPACE)) 
	//{
	//	if (playSpaceKey == false)
	//	{
	//		if (onground)
	//		{
	//			JUMP_SPEED = -sqrtf(2 * GRUVITY * JUMP_HEIGHT);
	//			onground = false;
	//			//canjump = true;
	//			
	//			//if (Jump_Counter > 4)
	//			//{
	//			//	//Jump_Counter = 3;
	//			//	Jump_Counter++; 
	//			//	
	//			//}
	//		}
	//	}
	//	playSpaceKey = true;
	//}
	//else 
	//{
	//	playSpaceKey =false;
	//	//canjump = true;
	//	//onground = true;
	//}
	
	onground = true;
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		if (playSpaceKey == false)//スペースキーを連続させない用
		{
			if (onground)
			{
				JUMP_SPEED = -sqrtf(2 * GRUVITY * JUMP_HEIGHT);
				onground = false;
			}
		}
		playSpaceKey = true;
	}
	else
	{
		playSpaceKey = false;
	}


	JUMP_SPEED += GRUVITY;//速度 + 加速度
	transform_.position_.y += JUMP_SPEED;
	//↓岩にぶつかる（右横）
	/*if (pField != nullptr) {
		int pushR = pField->CollisionDown(transform_.position_.x + 50, transform_.position_.y + 85);
		int pushL = pField->CollisionDown(transform_.position_.x + 40, transform_.position_.y + 85);
		int push = max(pushR, pushL);
		if (push > 0) {
			transform_.position_.x -= push;
			JUMP_SPEED = 0.0f;
			onground = true;
		}

		else {
			onground = false;
		}
	}*/
	//↓岩にぶつかる（左横）
	/*if (pField != nullptr) {
		int pushR = pField->CollisionDown(transform_.position_.x + 50, transform_.position_.y + 85);
		int pushL = pField->CollisionDown(transform_.position_.x + 40, transform_.position_.y + 85);
		int push = max(pushR, pushL);
		if (push > 0) {
			transform_.position_.x += push;
			JUMP_SPEED = 0.0f;
			onground = true;
		}
		else {
			onground = false;
		}
	}*/
	//↓下に落ちない
	if (pField != nullptr) {
		int pushR = pField->CollisionDown(transform_.position_.x + 50, transform_.position_.y + 85);
		int pushL = pField->CollisionDown(transform_.position_.x + 25, transform_.position_.y + 85);
		int push = max(pushR, pushL);
		if (push >= 1) {
			transform_.position_.y -= push-1;
			JUMP_SPEED = 0.0f;
			onground = true;
		}
		else {
			onground = false;
		}
	}
	//↓頭ぶつかる
	if (pField != nullptr) {
		int pushR = pField->CollisionDown(transform_.position_.x + 50, transform_.position_.y + 40);
		int pushL = pField->CollisionDown(transform_.position_.x + 25, transform_.position_.y + 40);
		int push = max(pushR, pushL);
		if (push > 0) {
			transform_.position_.y += push;
			JUMP_SPEED = 0.0f;
			onground = true;
		}
		else {
			onground = false;
		}
	}
	//↓カメラの位置を調整
	Camera* cam = GetParent()->FindGameObject<Camera>();
	//cam->SetValue(cam->GetValue() + 1.5f);

	int xR = (int)transform_.position_.x - cam->GetValue();
	if (xR > 400) {
		xR = 400;
		cam->SetValue((int)transform_.position_.x - xR);
	}
	int xL = (int)transform_.position_.x + cam->GetValue();
	if (xL > 400) {
		xL = 400;
		cam->SetValue((int)transform_.position_.x - xL);
	}

	//当たり判定player.cpp
	std::list<Enemy*> pEnemys = GetParent()->FindGameObjects<Enemy>();
	for (Enemy* pEnemy : pEnemys)
	{
		if (pEnemy->CollideCircle(transform_.position_.x+64, transform_.position_.y, 100.0f))
		{
			//当たった処理
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
			KillMe();

		}
		
	}

	std::list<Bullet*>pBullets = GetParent()->FindGameObjects<Bullet>();
	for (Bullet* pBullet : pBullets)
	{
		if (pBullet->ColliderCircle(transform_.position_.x + 63.0, transform_.position_.y, 63.0f))
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
			KillMe();
			
		}
		
	}

	std::list<thorn*>pThorns = GetParent()->FindGameObjects<thorn>();
	for (thorn* pthorn : pThorns)
	{
		if (pthorn->ColliderCircle(transform_.position_.x + 64.0, transform_.position_.y, 64.0f))
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
			KillMe();
		}
		
	}
	
}

void Player::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	//DrawRectGraph(x, y, animFrame * 60, 90, 62, 106, hImage, TRUE);
	DrawFormatString(0, 20, GetColor(255, 255, 255), "ジャンプの値:%d", Jump_Counter);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "ジャンプしてる？:%d", onground);
	//DrawFormatString(0, 60, GetColor(255, 255, 255), "空中でジャンプできる?:%d", canjump);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "スペース押してる？:%d", playSpaceKey);
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}

	DrawRectGraph(x, y, animFrame * 60, 190, 62, 106, hImage, TRUE);
}



void Player::SetPosition(int x, int y)
{
	transform_.position_.x;
	transform_.position_.y;
}

