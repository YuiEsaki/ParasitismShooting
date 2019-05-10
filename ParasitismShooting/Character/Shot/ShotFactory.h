#pragma once
#include "../../Geometry.h"
#include <list>
#include <map>

class Shot;

typedef std::list<Shot*> Legion;	// 弾の集合体の型

class ShotFactory
{
private:
	const Shot& shot;
	
	std::map<std::string, Shot*> originalShot;	// 弾の元となるmapの作成
	Legion legion;

public:
	ShotFactory(const Shot& shot);
	~ShotFactory();

	// 弾を作る
	// enemyname...弾の名前
	Shot* Create(const char* enemyname, Vector2f pos, int movePtn, int cnt, int wait, int hp, int sp, float speed);
	
	// 弾の集合体を返す
	Legion& GetLegion();
};

