#pragma once
#include "Engine/GameObject.h"
namespace
{
	//static const int SCREEN_WIDTH_SIZE = 1280;
	
}
class Bullet :
    public GameObject
{
public:
	Bullet(GameObject* scene);
	~Bullet();
	void Update() override;
	void Draw() override;
	void SetPosition(int x, int y);
	bool ColliderCircle(float x, float y, float r);
private:
	int hImage;
	float sinAngle;
	float sinValue;
	double vx;
};

