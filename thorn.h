#pragma once
#include "Engine/GameObject.h"
class thorn :
    public GameObject
{
public:
    thorn(GameObject* parent);
    ~thorn();
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

