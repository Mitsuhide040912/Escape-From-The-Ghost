#include "CannonBullet.h"
#include "Camera.h"
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
	transform_.position_.x -= 1.5f;
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
	DrawGraph(x, y, hImage, TRUE);
}

void CannonBullet::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

bool CannonBullet::ColliderCircle(float x, float y, float r)
{
	float myCenterX = transform_.position_.x + 200;
	float myCenterY = transform_.position_.y + 60;
	float dx = myCenterX - x;
	float dy = myCenterY - y;

	float dSqrts = dx * dx + dy * dy;
	float myR = 10.0f + r;
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
