#pragma once
#include "Engine/GameObject.h"
class thorn2 :
    public GameObject
{
public:
    thorn2(GameObject* parent);
    ~thorn2();
    void Update()override;
    void Draw()override;
    void SetPosition(int x, int y);
    bool ColliderCircle(float x, float y, float r);
private:
    int hImage;
    float sinAngle;
    float sinValue;
    double vx;
};

