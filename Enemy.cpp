#include "Enemy.h"
#include <assert.h>
#include "Camera.h"
#include "Player.h"
#include "FireBall.h"
Enemy::Enemy(GameObject* scene)
{
	hImage = LoadGraph("Assets/henkouEnemy4.png");
	assert(hImage > 0);
	transform_.position_.x = 0;
	transform_.position_.y = 0;
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
	transform_.position_.x += 1.8f;
	sinAngle += 3.0f;//“x
    sinValue = sinf(sinAngle * DX_PI_F / 180.0f);
	transform_.position_.y = 300.0f + sinValue * 10.0f;
	if (timer_ <= 0)
	{
		FireBall* fb = Instantiate<FireBall>(GetParent());
		fb->SetPosition(transform_.position_.x, transform_.position_.y);
		timer_ = 360;
	}
	if (timer_ > 0)
	{
		timer_--;
	}
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
	
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr) {
		x -= cam->GetValue();
	}
	//DrawCircle(x+128 , y+128 , 148.0f, GetColor(255, 0, 0));//“–‚½‚è”»’è
	DrawGraph(x, y, hImage, TRUE);
}

void Enemy::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y + sinValue * 10.0f;
}

bool Enemy::CollideCircle(float x, float y, float r)
{
	float myCenterX = transform_.position_.x + 64;
	float myCenterY = transform_.position_.y + 64;
	
	float dx = myCenterX - x;
	float dy = myCenterY - y;
	
	float dSqrts = dx * dx + dy * dy;
	float myR = 128.0f + r;
	float rSqrt = myR * myR;
	if (dSqrts <= rSqrt)
	{
		return true;
	}
	else
	{
		return false;
	}
}
