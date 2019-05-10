#pragma once
#include "../../Geometry.h"
#include <list>
#include <map>

class Shot;
class Player;

typedef std::list<Shot*> Legion;	// 弾の集合体の型

class ShotFactory
{
private:
	const Player& player;
	
	std::map<std::string, Shot*> originalShot;	// 弾の元となるmapの作成
	Legion legion;

public:
	ShotFactory(const Player& player);
	~ShotFactory();

	// 弾を作る
	// enemyname...弾の名前
	Shot* Create(const char* enemyname, Vector2f pos, int movePtn, int cnt, int wait, int hp, int sp, float speed);
	
	// 弾の集合体を返す
	Legion& GetLegion();
};

