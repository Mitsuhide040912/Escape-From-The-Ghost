#pragma once
#include "Engine/GameObject.h"
class PlayScene :
	public GameObject
{
	int sound;
	int SHandle;
public:
	PlayScene(GameObject* parent);

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};

