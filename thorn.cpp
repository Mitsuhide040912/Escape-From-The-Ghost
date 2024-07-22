#include "thorn.h"
#include "Camera.h"
#include <assert.h>
thorn::thorn(GameObject* parent)
{
	hImage = LoadGraph("Assets/Dossun.png");
	assert(hImage > 0);
	transform_.position_.x;
	transform_.position_.y;
}

thorn::~thorn()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void thorn::Update()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	//transform_.position_.y -= 0.1f;
	sinAngle += 3.0f;
	sinValue = sinf(sinAngle * DX_PI_F / 180.0f);
	transform_.position_.y = 300.0f + sinValue * 100.0f;
}

void thorn::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	//DrawCircle(x+64 , y+70 , 60.0f, GetColor(255, 0, 0));//“–‚½‚è”»’è
	DrawGraph(x, y, hImage, TRUE);
}

void thorn::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

bool thorn::ColliderCircle(float x, float y, float r)
{
	float myCenterX = transform_.position_.x + 88.0;
	float myCenterY = transform_.position_.y + 32.0;
	float dx = myCenterX - x;
	float dy = myCenterY - y;

	float dSqrts = dx * dx + dy * dy;
	float myR = 60.0f + r;
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
