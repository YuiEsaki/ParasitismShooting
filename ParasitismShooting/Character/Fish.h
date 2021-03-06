#pragma once
#include "Enemy.h"
#include "CharacterObject.h"

class Player;
class EnemyFactory;

// 
class Fish : public Enemy
{
	friend EnemyFactory;
private:
	Fish(const Player& player);		// Ά¬Φ~
	Fish(const Fish&);				// ΊΛί°Φ~
	void operator=(const Fish&);	// γόΦ~

	Enemy* Clone();

	void Move();
	void Die();
	void Stunning();
	void StunDamage();
	void Damage();
	
	void (Fish::*updater)();

	const Player& player;
public:
	~Fish();

	void Update();
	void Draw(int time);
};
