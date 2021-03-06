#pragma once
#include "../Geometry.h"
#include <list>
#include <string>
#include <map>

class Enemy;
class Player;

typedef std::list<Enemy*> ELegion;	// 敵の集合体の型

class EnemyFactory
{
private:
	const Player& player;
	
	std::map<std::string, Enemy*> originalEnemy;	// 敵の元となるmapの作成
	ELegion legion;

	int up;
	int right;
	int left;
	int down;

public:
	EnemyFactory(const Player& player);
	~EnemyFactory();

	// 敵を作る
	// enemyname...敵の名前
	Enemy* Create(const char * enemyname, const char * shotType, Vector2f pos, int movePtn, int cnt, int wait, int hp, int sp, float speed, int shotCnt, int shotLevel,const int & stageNum);

	// 敵の集合体を返す
	ELegion& GetLegion();

	Vector2f GetLegionBeginCharPos()const;
	// ダメージ弾に当たったを消す
	void EnemyDelete();
	void OutofScreen();
};
