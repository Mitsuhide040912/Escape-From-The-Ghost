#pragma once
#include "Engine/GameObject.h"
class GameClear :
    public GameObject
{
public:
	GameClear(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
private:
	int hImage;
	int hTitleScene;
	int sound;
};

