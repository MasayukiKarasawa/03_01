#pragma once
#include "IScene.h"
class StageScene : public IScene
{
public:
	void Init() override;
	void Update() override;
	void Draw() override;


	int enemyposX = 100;
	int enemyposY = 100;
	int enemyradius = 25;
	int speed = 3;
	int isenemyalive = true;


	int playerposX = 640;
	int	playerposY = 600;
	int playersize = 50;
	int playerspeed = 7;

	int bulletposX = 0;
	int bulletposY = 0;
	int bulletsize = 10;
	int bulletspeed = 5;
	int isBulletShot = false;
	int bulletradius = 5;
};

