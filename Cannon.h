#pragma once
#include "Engine/GameObject.h"
class Cannon :
    public GameObject
{
public:
	Cannon(GameObject* scene);
	~Cannon();
	void Update() override;
	void Draw() override;
	void SetPosition(int x, int y);
	bool CollideCircle(float x, float y, float r);
private:
	int hImage;
	float sinAngle;
	float sinValue;
	double vx;//
	int timer_;
	int interval = 3000;
};

