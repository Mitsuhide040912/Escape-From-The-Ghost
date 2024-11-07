#pragma once
#include "Engine/GameObject.h"

class ShineBullet :
    public GameObject
{
public:
	ShineBullet(GameObject* scene);
	~ShineBullet();
	void Update() override;
	void Draw() override;
	void SetPosition(int x, int y);
	bool ColliderCircle(float x, float y, float r);
private:
	int hImage;
	float timer_;
};

