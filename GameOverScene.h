#pragma once
#include "Engine/GameObject.h"
class GameOverScene :
    public GameObject
{
public:
	GameOverScene(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
private:
	int hImage;
	int hTitleScene;
};

