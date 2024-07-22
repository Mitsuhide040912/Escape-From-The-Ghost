#include "Cannon2.h"
#include"Camera.h"
#include <assert.h>
#include "Player.h"
#include "CannonBullet.h"
Cannon2::Cannon2(GameObject* scene)
{
    hImage = LoadGraph("Assets/Cannon.png");
    assert(hImage > 0);
    transform_.position_.x;
    transform_.position_.y;
}

Cannon2::~Cannon2()
{
    if (hImage > 0)
    {
        DeleteGraph(hImage);
    }
}

void Cannon2::Update()
{
    int x = (int)transform_.position_.x;
    int y = (int)transform_.position_.y;
    if (timer_ <= 0)
    {
        CannonBullet* cb = Instantiate<CannonBullet>(GetParent());
        cb->SetPosition(transform_.position_.x, transform_.position_.y);
        timer_ = 720;
    }
    if (timer_ > 0)
    {
        timer_--;
    }
}

void Cannon2::Draw()
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

void Cannon2::SetPosition(int x, int y)
{
    transform_.position_.x = x;
    transform_.position_.y = y;
}

bool Cannon2::CollideCircle(float x, float y, float r)
{
    return false;
}
