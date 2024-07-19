#include "Bullet.h"
#include "Camera.h"
#include "thorn.h"
#include "Player.h"
#include <assert.h>
Bullet::Bullet(GameObject* scene)
{
	hImage = LoadGraph("Assets/Kaoru.png");
	assert(hImage > 0);
	transform_.position_.x = 0;
	transform_.position_.y = 0;
	
}

Bullet::~Bullet()
{
	if (hImage > 0)
	{
		DeleteGraph(hImage);
	}
}

void Bullet::Update()
{
	static int x = (int)transform_.position_.x;
	static int y = (int)transform_.position_.y;
	transform_.position_.x += 3.5f;
	sinAngle += 3.0f;
	sinValue = sinf(sinAngle * DX_PI_F / 180.0f);
	//transform_.position_.x = x + sinValue * 40.0f;
	//transform_.position_.y = y + sinValue * 40.0f;
	//«ƒhƒbƒXƒ“‚É“–‚½‚Á‚½
	std::list<thorn*>pthorns = GetParent()->FindGameObjects<thorn>();
	for (thorn* pthorn : pthorns)
	{
		if (pthorn->ColliderCircle(transform_.position_.x + 64, transform_.position_.y, 100.0f))
		{
			//“–‚½‚Á‚½ˆ—
			KillMe();
		}
	}

	/*while (ProcessMessage()==0)
	{
		int bullet_speed = 3.5f;
		int dx = transform_.position_.x;
		int dy = transform_.position_.y;
		double angle = atan2(dx, dy);
		int bulletX = enemyX + static_cast<int>(cos(angle) * bullet_speed);
		int bulletY = enemyY + static_cast<int>(sin(angle) * bullet_speed);
	}*/
}

void Bullet::Draw()
{
	int x = (int)transform_.position_.x;
	int y = (int)transform_.position_.y;
	
	Camera* cam = GetParent()->FindGameObject<Camera>();
	if (cam != nullptr) {
		x -= cam->GetValue();
	}
	//DrawCircle(x+28 , y+28 , 50.0f, GetColor(255, 0, 0));//“–‚½‚è”»’è
	DrawGraph(x, y, hImage, TRUE);
}

void Bullet::SetPosition(int x, int y)
{
	transform_.position_.x = x;
	transform_.position_.y = y;
}

bool Bullet::ColliderCircle(float x, float y, float r)
{
	//x,y,r‚ª‘Šè‚Ì‰~‚Ìî•ñ
	//©•ª‚Ì‰~‚Ìî•ñ
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
