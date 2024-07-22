#include "FireBall.h"
#include "Camera.h"
#include <assert.h>
FireBall::FireBall(GameObject* scene)
{
	hImage = LoadGraph("Assets/FIREBall2.png");
	assert(hImage > 0);
	transform_.position_.x;
	transform_.position_.y;
}

FireBall::~FireBall()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void FireBall::Update()
{
	transform_.position_.x += 3.0f;
}

void FireBall::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	//DrawCircle(x+150 , y+130 , 15.0f, GetColor(255, 0, 0));//“–‚½‚è”»’è
	DrawGraph(x + 125, y + 120, hImage, TRUE);
}

void FireBall::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

bool FireBall::ColliderCircle(float x, float y, float r)
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
