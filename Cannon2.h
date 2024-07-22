#pragma once
#include "Engine/GameObject.h"
class Cannon2 :
    public GameObject
{
public:
	Cannon2(GameObject* scene);
	~Cannon2();
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

