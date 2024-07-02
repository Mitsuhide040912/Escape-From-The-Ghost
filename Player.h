#pragma once
#include "Engine/GameObject.h"
class Player :
    public GameObject
{
    int hImage;
    bool onground;
    bool playSpaceKey;
    float JUMP_SPEED;
    int animType;
    int animFrame;
    int FrameCounter;
    int value;
public:
    Player(GameObject* scene);
    ~Player();
    void Update()override;
    void Draw()override;
    void SetValue(int v) { value = v; }
    int GetValue() { return value; }
};

