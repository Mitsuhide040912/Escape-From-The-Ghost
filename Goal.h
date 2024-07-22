#pragma once
#include "Engine/GameObject.h"
class Goal :
    public GameObject
{
public:
	Goal(GameObject* parent);
	~Goal();
	void Update() override;
	void Draw() override;
	void SetPosition(int x, int y);
	bool ColliderCircle(float x, float y, float r);
private:
    int hImage;
	int x1;
	int y1;
	int x2;
	int y2;
	int rx;
	int ry;
	int Color;
	int FillFlag;
};

