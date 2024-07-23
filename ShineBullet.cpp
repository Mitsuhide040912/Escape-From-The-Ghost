#include "ShineBullet.h"
#include "Camera.h"
#include "CannonBullet.h"
#include <assert.h>
ShineBullet::ShineBullet(GameObject* scene)
	:GameObject()
{
	hImage = LoadGraph("Assets/shineBullet.png");
	assert(hImage > 0);
	transform_.position_.x = 0;
	transform_.position_.y = 0;
}

ShineBullet::~ShineBullet()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void ShineBullet::Update()
{
	static int x = (int)transform_.position_.x;
	static int y = (int)transform_.position_.y;
	transform_.position_.x += 3.5f;

	//std::list<CannonBullet*>pCBs = GetParent()->FindGameObjects<CannonBullet>();
	//for (CannonBullet* pCB : pCBs)
	//{
	//	if (pCB->ColliderCircle(transform_.position_.x + 64, transform_.position_.y, 60.0f))
	//	{
	//		//“–‚½‚Á‚½ˆ—
	//		KillMe();
	//	}
	//}
}

void ShineBullet::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;

	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr) {
		x -= cam->GetValue();
	}
	//DrawCircle(x+28 , y+28 , 50.0f, GetColor(255, 0, 0));//“–‚½‚è”»’è
	DrawGraph(x + 90, y + 10, hImage, TRUE);
}

void ShineBullet::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

bool ShineBullet::ColliderCircle(float x, float y, float r)
{
	float myCenterX = transform_.position_.x + 10.5;
	float myCenterY = transform_.position_.y + 10.5;
	float dx = myCenterX - x;
	float dy = myCenterY - y;

	float dSqrts = dx * dx + dy * dy;
	float myR = 10.5f + r;
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
