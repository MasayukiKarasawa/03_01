#include "StageScene.h"
#include"Novice.h"
void StageScene::Init()
{
	
}

void StageScene::Update()
{
	/// 敵の自動移動処理
	enemyposX = enemyposX + speed;

	if (enemyposX + enemyradius >= 1280) {

		speed = speed * -1;
	}

	if (enemyposX - enemyradius <= 0) {

		speed = speed * -1;

	}

	if (playerposX + playersize >= 1280)
	{
		playerposX = 1280 - playersize;
	}

	if (playerposX - (playersize - 50) <= 0)
	{
		playerposX = 0 + (playersize - 50);
	}

	if (playerposY + playersize >= 720)
	{
		playerposY = 720 - playersize;
	}

	if (playerposY - (playersize - 50) <= 0)
	{
		playerposY = 0 + (playersize - 50);
	}



	//プレイヤーの移動処理

	if (keys_[DIK_W])
	{
		playerposY = playerposY - playerspeed;
	}

	if (keys_[DIK_A])
	{
		playerposX = playerposX - playerspeed;
	}

	if (keys_[DIK_D])
	{
		playerposX = playerposX + playerspeed;
	}

	if (keys_[DIK_S])
	{
		playerposY = playerposY + playerspeed;
	}

	//弾の発射処理

	if (isBulletShot == 0)
	{

		if (keys_[DIK_SPACE] && preKeys_[DIK_SPACE] == 0)
		{

			isBulletShot = true;
			bulletposX = playerposX;
			bulletposY = playerposY;
		}
	}
	if (isBulletShot == 1)
	{
		bulletposY = bulletposY - bulletspeed;
	}

	if (bulletposY <= 0)
	{
		isBulletShot = false;
	}

	//当たり判定
	int d;
	d = (enemyposX - bulletposX) * (enemyposX - bulletposX) + (enemyposY - bulletposY) * (enemyposY - bulletposY);
	int r;
	r = (enemyradius - bulletradius) * (enemyradius - bulletradius);
	//弾が当たった（接した）または交わっていた時の処理
	if (r == d || r > d)
	{
		isBulletShot = false;
		isenemyalive = false;
		(bulletposX, bulletposY = -10);
		sceneNo = kClear;
	}




	/*if (keys_[DIK_SPACE] && preKeys_[DIK_SPACE]) {
		sceneNo = kClear;
	}*/
}

void StageScene::Draw()
{
	Novice::ScreenPrintf(1280 / 2, 720 / 2, "StageScene");
	if (isBulletShot == 1)
	{
		Novice::DrawTriangle(bulletposX, bulletposY - 5, bulletposX - 5, bulletposY + 5, bulletposX + 5, bulletposY + 5, RED, kFillModeSolid);
	}
	Novice::DrawBox(playerposX, playerposY, playersize, playersize, 0.0F, WHITE, kFillModeSolid);
	Novice::ScreenPrintf(0, 0, "player: posX: %d , posY: %d", playerposX, playerposY);
	Novice::ScreenPrintf(0, 20, "Bullet: posX: %d , posY: %d , isBulletShot: %d", bulletposX, bulletposY, isBulletShot);
	Novice::ScreenPrintf(0, 40, "Enemy: posX: %d , posY: %d , isEnemyalive: %d", enemyposX, enemyposY, isenemyalive);
	if (isenemyalive == 1)
	{
		Novice::DrawEllipse(enemyposX, enemyposY, enemyradius, enemyradius, 0.0F, WHITE, kFillModeSolid);
	}
}
