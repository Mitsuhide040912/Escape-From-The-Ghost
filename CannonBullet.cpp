#include "CannonBullet.h"
#include "Camera.h"
#include "ShineBullet.h"
#include <assert.h>
CannonBullet::CannonBullet(GameObject* scene)
{
	hImage = LoadGraph("Assets/Gyorai.png");
	assert(hImage > 0);
	transform_.position_.x;
	transform_.position_.y;
}

CannonBullet::~CannonBullet()
{
	if (hImage > 0);
	{
		DeleteGraph(hImage);
	}
}

void CannonBullet::Update()
{
	transform_.position_.x -= 1.3f;
	std::list<ShineBullet*>pShineBullets = GetParent()->FindGameObjects<ShineBullet>();
	for (ShineBullet* pShineBullet : pShineBullets)
	{
		if (pShineBullet->ColliderCircle(transform_.position_.x + 64, transform_.position_.y, 60.0f))
		{
			//“–‚½‚Á‚½ˆ—
			KillMe();
		}
	}
}

void CannonBullet::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	//DrawCircle(x + 50, y + 70, 50.0f, GetColor(255, 0, 0));//“–‚½‚è”»’è
	DrawGraph(x, y, hImage, TRUE);
}

void CannonBullet::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

bool CannonBullet::ColliderCircle(float x, float y, float r)
{
	float myCenterX = transform_.position_.x + 100;
	float myCenterY = transform_.position_.y + 50;
	float dx = myCenterX - x;
	float dy = myCenterY - y;

	float dSqrts = dx * dx + dy * dy;
	float myR = 30.0f + r;
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
