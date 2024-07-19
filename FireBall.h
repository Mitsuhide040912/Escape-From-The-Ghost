#pragma once
#include "Engine/GameObject.h"
class FireBall :
    public GameObject
{
public:
	FireBall(GameObject* scene);
	~FireBall();
	void Update() override;
	void Draw() override;
	void SetPosition(int x, int y);
	bool ColliderCircle(float x, float y, float r);
private:
	int hImage;
};

