#include "Cannon.h"
#include "Camera.h"
#include <assert.h>
#include "Player.h"
#include "CannonBullet.h"
Cannon::Cannon(GameObject* scene)
{
	hImage = LoadGraph("Assets/Cannon.png");
	assert(hImage > 0);
	transform_.position_.x = 0;
	transform_.position_.y = 0;
}

Cannon::~Cannon()
{
	if (hImage > 0);
	{
		DeleteGraph(hImage);
	}
}

void Cannon::Update()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	if (timer_ <= 0)
	{
		CannonBullet* cb = Instantiate<CannonBullet>(GetParent());
		cb->SetPosition(transform_.position_.x, transform_.position_.y);
		timer_ = 1440;
	}
	if (timer_ > 0)
	{
		timer_--;
	}
}

void Cannon::Draw()
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

void Cannon::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

bool Cannon::CollideCircle(float x, float y, float r)
{
	return false;
}
