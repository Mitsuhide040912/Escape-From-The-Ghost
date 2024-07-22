#include "Goal.h"
#include "Camera.h"
#include <assert.h>

Goal::Goal(GameObject* parent)
{
	hImage = LoadGraph("Assets/Goal_Flag.png");
	assert(hImage > 0);
	transform_.position_.x = 0;
	transform_.position_.y = 0;
}

Goal::~Goal()
{
}

void Goal::Update()
{
}

void Goal::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr) {
		x -= cam->GetValue();
	}
	//DrawCircle(x+85 , y+28 , 50.0f, GetColor(255, 0, 0));//“–‚½‚è”»’è
	//DrawBox(x + 30,y + 30, 300.0f, 300.0f, Color, TRUE);
	DrawGraph(x, y, hImage, TRUE);
}

void Goal::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

bool Goal::ColliderCircle(float x, float y, float r)
{
	float myCenterX = transform_.position_.x + 140.0;
	float myCenterY = transform_.position_.y + 10.0;
	float dx = myCenterX - x;
	float dy = myCenterY - y;

	float dSqrts = dx * dx + dy * dy;
	float myR = 30.5f + r;
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
