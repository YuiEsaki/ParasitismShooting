#pragma once
#include "Shot.h"

class EnemyFactory;
class ShotFactory;

// 分散弾
// レベルにより分散数が増える
class Shotgun : public Shot
{
	friend ShotFactory;
private:
	Shotgun(const Player& player, const EnemyFactory& enemyfactory);
	Shotgun(const Shotgun&);
	void operator=(const Shotgun&);

	Shot* Clone();

	void Move();
	void Delete();
	
	void (Shotgun::*updater)();

	const Player& player;
	const EnemyFactory& enemyfactory;


public:
	~Shotgun();

	void Update();
	void Draw();
	
};
