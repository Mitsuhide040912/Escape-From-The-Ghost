#include "Bullet.h"
#include "CoolTimer.h"
#include "Camera.h"
#include <assert.h>
Bullet::Bullet(GameObject* scene)
{
	hImage = LoadGraph("Assets/Kaoru.png");
	assert(hImage > 0);
	transform_.position_.x = -100.0f;
	transform_.position_.y = 800.0f;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	transform_.position_.x += 3.5f;
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr)
	{
		x -= cam->GetValue();
	}
	if (SCREEN_WIDTH_SIZE)
		return;
}

void Bullet::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	DrawGraph(x, y, hImage, TRUE);
}
