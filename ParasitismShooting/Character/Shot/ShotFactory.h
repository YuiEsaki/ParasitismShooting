#pragma once
#include "../../Geometry.h"
#include <list>
#include <map>

class Shot;
class Player;
class Enemy;

typedef std::list<Shot*> SLegion;	// 弾の集合体の型

class ShotFactory
{
private:
	const Player& player;
	
	std::map<std::string, Shot*> originalShot;	// 弾の元となるmapの作成
	SLegion legion;

public:
	ShotFactory(const Player& player/*, const Enemy& enemy*/);
	~ShotFactory();

	// 弾を作る
	// enemyname...弾の名前
	Shot* Create(const char * shotname,Vector2f pos, float angle, int Speed, int movePtn, int level, int shotPtn, int shooter);
	
	// 弾の集合体を返す
	SLegion& GetLegion();
	// 他のものに当たった弾を消す
	void ShotDelete();
};

