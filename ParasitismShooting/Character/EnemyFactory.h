#pragma once
#include "../Geometry.h"
#include <list>
#include <map>

class Enemy;
class Player;

typedef std::list<Enemy*> Legion;	// 敵の集合体の型

class EnemyFactory
{
private:
	const Player& player;
	
	std::map<std::string, Enemy*> originalEnemy;	// 敵の元となるmapの作成
	Legion legion;

public:
	EnemyFactory(const Player& player);
	~EnemyFactory();

	// 敵を作る
	// enemyname...敵の名前
	Enemy* Create(const char * enemyname, Vector2f pos, int movePtn, int cnt, int wait, int hp, int sp, float speed);
	
	// 敵の集合体を返す
	Legion& GetLegion();
};

