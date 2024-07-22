#include "Field.h"
#include "DxLib.h"
#include <assert.h>
#include "Engine/CsvReader.h"
#include "Camera.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "thorn.h"
#include "Goal.h"
#include "Cannon.h"
#include "Cannon2.h"
Field::Field(GameObject* parent)
	:GameObject(parent)
{
	Map = nullptr;
	hImage = LoadGraph("Assets/bgchar.png");
	assert(hImage > 0);

	hBackGround = LoadGraph("Assets/GhostMap.png");
	assert(hBackGround > 0);
	Reset();
}

Field::~Field()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
	if (hBackGround > 0)
	{
		DeleteGraph(hBackGround);
	}
	if (Map != nullptr)
	{
		delete[]Map;
	}
}

void Field::Update()
{
	if (CheckHitKey(KEY_INPUT_R))
	{
		Reset();
	}
}

void Field::Draw()
{
	int screenWidth, screenHeight, colorBitDepth;
	GetScreenState(&screenWidth, &screenHeight, &colorBitDepth);

	DrawExtendGraph(0, 0, screenWidth, screenHeight, hBackGround, FALSE);
	int scroll = 0;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		scroll -= cam->GetValue();
	}

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			int chip = Map[y * width + x];
			DrawRectGraph(x * 32 + scroll, y * 32, 32 * (chip % 16), 32 * (chip / 16), 32, 32, hImage, TRUE);
		}
	}
}

void Field::Reset()
{
	if (Map != nullptr) {
		delete[]Map;
		Map = nullptr;
	}
	CsvReader csv;
	bool ret = csv.Load("Assets/stage1.csv");
	assert(ret);

	width = csv.GetWidth();
	height = 22;//csv.GetHeight();
	Map = new int[width * height];

	/*for (int h = 0; h < height; h++){
		if (csv.GetString(0, h) == "") {
			height = h;
			break;
		}
		for (int w = 0; w < width; w++){
			Map[h * width + w] = csv.GetInt(w, h);
		}
	}*/

	for (int h = 0; h < height; h++){
		for (int w = 0; w < width; w++) {
			switch (csv.GetInt(w, h/*+height+1*/))
			{
			 case 0:
			 {
				Player* pPlayer = GetParent()->FindGameObject<Player>();
				pPlayer->SetPosition(w * 32, h * 32);
				break;
			 }
			 case 1:
			 {
				Enemy* pEnemy = Instantiate<Enemy>(GetParent());
				pEnemy->SetPosition(w * 32, h * 32);
				break;
			 }
			 case 2:
			 {
				Bullet* pBullet = Instantiate<Bullet>(GetParent());
				pBullet->SetPosition(w * 32, h * 32);
				break;
			 }
			 case 3:
			 {
				 thorn* pThorn = Instantiate<thorn>(GetParent());
				 pThorn->SetPosition(w * 32, h * 32);
				 break;
			 }
			 case 4:
			 {
				 Goal* pGoal = Instantiate<Goal>(GetParent());
				 pGoal->SetPosition(w * 32, h * 32);
				 break;
			 }
			 case 5:
			 {
				 Cannon* pCannon = Instantiate<Cannon>(GetParent());
				 pCannon->SetPosition(w * 32, h * 32);
				 break;
			 }
			 case 6:
			 {
				 Cannon2* pCannon2 = Instantiate<Cannon2>(GetParent());
				 pCannon2->SetPosition(w * 32, h * 32);
				 break;
			 }
			 default:
				 break;
			}
			
				Map[h * width + w] = csv.GetInt(w, h);
		}
	}
}

int Field::CollisionRight(int x, int y)
{
	if (IsWallBlock(x + 1, y))
	{
		return (x + 1) % 32 + 1;
	}
	return 0;
}

int Field::CollisionLeft(int x, int y)
{
	if (IsWallBlock(x - 1, y))
	{
		return 32 - (x % 32);
	}
	return 0;
}

int Field::CollisionDown(int x, int y)
{
	if (IsWallBlock(x,y + 1))
	{
		return (y + 1) % 32 + 1;
	}
	return 0;
}

bool Field::IsWallBlock(int x, int y)
{
	
	int chipX = x / 32;
	int chipY = y / 32;
	switch (Map[chipY * width + chipX]) {
	case 16:
	case 17:
	case 18:
	case 19:
	case 32:
	case 33:
	case 34:
	case 35:
		return true;
	}
	return false;
}

