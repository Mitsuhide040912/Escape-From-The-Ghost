#pragma once
#include "Engine/GameObject.h"
namespace {
	static const int SCREEN_WIDTH = 1280;
	static const int ZERO = 0;
}
class Enemy : public GameObject
{
public:
	Enemy(GameObject* scene);
	~Enemy();
	void Update() override;
	void Draw() override;

private:
	int hImage;
	float sinAngle;
	bool CollideCircle(float x, float y, float r);
	double vx;//
};


