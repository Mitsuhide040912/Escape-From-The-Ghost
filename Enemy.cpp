#include "Enemy.h"
//#include "Bird.h"
#include <assert.h>
#include "Camera.h"
#include "Player.h"
Enemy::Enemy(GameObject* scene)
{
	hImage = LoadGraph("Assets/snake.png");
	assert(hImage > 0);
	transform_.position_.x = -400.0f;
	transform_.position_.y = 800.0f;
}

Enemy::~Enemy()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void Enemy::Update()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	transform_.position_.x += 0.5f;
	sinAngle += 3.0f;//�x
	float sinValue = sinf(sinAngle * DX_PI_F / 180.0f);
	transform_.position_.y = 500.0f + sinValue * 10.0f;

	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr) {
		x -= cam->GetValue();
	}

	if (x > SCREEN_WIDTH)
		return;

	/*x += static_cast<int>(vx);
	Player* pPlayer = GetParent()->FindGameObject<Player>();
	pPlayer->Update();
	Bird* pBird = GetParent()->FindGameObject<Bird>();
	pBird->Update();
	if (std::abs(transform_.position_.x - transform_.position_.x) < 100)
	{
		transform_.position_.x = transform_.position_.x;
	}*/


	/*else if (x < -64) {
		KillMe();
		return;
	}*/
}

void Enemy::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	DrawGraph(x, y, hImage, TRUE);
	/*Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr) {
		x -= cam->GetValue();
	}*/
}

void Enemy::SetPosition(int x, int y)
{
	transform_.position_.x;
	transform_.position_.y;
}

bool Enemy::CollideCircle(float x, float y, float r)
{
	float myCenterX = transform_.position_.x + 32.0f;
	float myCenterY = transform_.position_.y + 32.0f;
	float myR = 24.0f;
	float dx = myCenterX - x;
	float dy = myCenterY - y;
	if (dx * dx + dy + dy < (r + myR) * (r + myR));
	return false;
}