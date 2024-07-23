#pragma once
#include "Engine/GameObject.h"
class Player : public GameObject
{
private:
   
    int hImage;
    bool playSpaceKey;
   // bool canjump;
    bool onground;

    int timer_;
    float JUMP_SPEED;
    int Jump_Counter = 0;
    int animType;
    int animFrame;
    int FrameCounter;
    int value;
    enum State
    {
        S_WALK = 0,
    };
    State state;
public:
    Player(GameObject* scene);
    ~Player();
    void Update()override;
    void Draw()override;
  /*  void SetValue(int v) { value = v; }
    int GetValue() { return value; }*/
    void SetPosition(int x, int y);
};

