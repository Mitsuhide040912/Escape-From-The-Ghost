#pragma once
#include "Engine/GameObject.h"
namespace
{
	static const int SCREEN_WIDTH_SIZE = 1280;
	
}
class Bullet :
    public GameObject
{
public:
	Bullet(GameObject* scene);
	~Bullet();
	void Update() override;
	void Draw() override;
private:
	int hImage;
};

