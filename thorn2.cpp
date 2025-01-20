#include "thorn2.h"
#include "Camera.h"
#include <assert.h>
thorn2::thorn2(GameObject* parent)
{
	hImage = LoadGraph("Assets/Stone.png");
	assert(hImage > 0);
	
	transform_.position_.x;
	transform_.position_.y;
}

thorn2::~thorn2()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void thorn2::Update()
{
	transform_.rotate_.x = 180;
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
}

void thorn2::Draw()
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

void thorn2::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

bool thorn2::ColliderCircle(float x, float y, float r)
{

	float myCenterX = transform_.position_.x + 50.0;
	float myCenterY = transform_.position_.y + 5.0;
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
