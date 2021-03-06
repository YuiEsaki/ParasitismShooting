#pragma once
#include "Enemy.h"
#include "CharacterObject.h"

class Player;
class EnemyFactory;

// G―
class Ika : public Enemy
{
	friend EnemyFactory;
private:
	Ika(const Player& player);	// Ά¬Φ~
	Ika(const Ika&);			// ΊΛί°Φ~
	void operator=(const Ika&);	// γόΦ~

	Enemy* Clone();

	void Move();
	void Die();
	void Stunning();
	void StunDamage();
	void Damage();
	
	Vector2f basePos;
	float vecAngle;

	void orginalMove(int movePtn, Vector2f & pos, float speed, int cnt, int wait, int shotCnt, int charSP, bool& ShotReady);
	void (Ika::*updater)();

	const Player& player;
public:
	~Ika();

	void Update();
	void Draw(int time);
};
