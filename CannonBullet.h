#pragma once
#include "Engine/GameObject.h"
class CannonBullet :
    public GameObject
{
public:
	CannonBullet(GameObject* scene);
	~CannonBullet();
	void Update() override;
	void Draw() override;
	void SetPosition(int x, int y);
	bool ColliderCircle(float x, float y, float r);
private:
	int hImage;
};

