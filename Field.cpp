#include "Field.h"
#include "DxLib.h"
#include <assert.h>
#include "Engine/CsvReader.h"
#include "Camera.h"
#include "Player.h"
#include "Enemy.h"
Field::Field(GameObject* parent)
	:GameObject(parent)
{
	hImage = LoadGraph("Assets/bgchar.png");
	assert(hImage > 0);
}

Field::~Field()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
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
	/*Camera* cam = GetParent()->FindGameObject<Camera>();
	cam->SetValue(cam->GetValue() + 1);*/
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
	bool ret = csv.Load("Assets/stage01.csv");
	assert(ret);
	width = csv.GetWidth(0);
	height = 22;//csv.GetHeight();
	Map = new int[width * height];


	for (int h = 0; h < height; h++){
		if (csv.GetString(0, h) == "") {
			height = h;
			break;
		}
		for (int w = 0; w < width; w++){
			Map[h * width + w] = csv.GetInt(w, h);
		}
	}
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			switch (csv.GetInt(w,h+height+1))
			{
			case 0:
			{
				Player* pPlayer = GetParent()->FindGameObject<Player>();
				pPlayer->SetPosition(w * 32, h * 32);
			}
			case 1:
			{
				Enemy* pEnemy = GetParent()->FindGameObject<Enemy>();
				pEnemy->SetPosition(w * 32, h * 32);
			}
				break;
			}
		}
	}
	/*for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			int chip = Map[x][y];
			DrawRectGraph(x * 32, y * 32, 32 * (chip / 16), 32 * (chip / 16), 32, 32, hImage, TRUE);
		}
	}*/
}

int Field::CollisionRight(int x, int y)
{
	/*if (IsWallBlock(x, y))
	{
		return y % 32 + 1;
		return 0;
	}*/
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
	return 0;
}

int Field::CollisionLeft(int x, int y)
{
	/*if (IsWallBlock(x, y))
	{
		return y % 32 - 1;
		return 0;
	}*/
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
	return 0;
}

int Field::CollisionDown(int x, int y)
{
	/*if (IsWallBlock(x, y))
	{
		return y % 32 + 1;
		return 0;
	}*/
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

