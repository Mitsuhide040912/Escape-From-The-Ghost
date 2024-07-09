#pragma once
#include "Engine/GameObject.h"
#include "DxLib.h"
class Field :
    public GameObject
{
public:
    Field(GameObject* parent);
    ~Field();
    void Update()override;
    void Draw();
    void Reset();
    int CollisionRight(int x, int y);
    int CollisionLeft(int x, int y);
    int CollisionDown(int x, int y);
    //int CollisionUp(int x, int y);
private:
    int hImage;
    bool IsWallBlock(int x, int y);
    int* Map;
    int width;
    int height;
};
