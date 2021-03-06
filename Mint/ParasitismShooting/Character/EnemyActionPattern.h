#pragma once
#include <iostream>
#include "../Geometry.h"
class Player;

enum MovementPTN
{
	UpDown,
	LeftRight,
	Rush,
	Wavy,
	Stun,
	FadeOut,
	MOVEMENT_PTN_MAX
};

class EnemyActionPattern
{
public:
	EnemyActionPattern();
	~EnemyActionPattern();
	void Update(int movePtn, Vector2f & pos, float speed, int cnt, int wait, int shotCnt, int charSP, bool& ShotReady);
private:
	void UpDown(Vector2f &pos, float speed, int cnt, int wait);		// 上下移動
	void LeftRight(Vector2f &pos, float speed, int cnt, int wait);		// 左右に履ける
	void Rush(Vector2f &pos, float speed, int cnt, int wait);		// 自機に特攻を仕掛ける
	void Wavy(Vector2f &pos, float speed, int cnt, int wait);		// 波状移動
	void FadeOut(Vector2f &pos, float speed, int cnt, int wait);
	void Stun(Vector2f &pos, float speed);		// 気絶状態

	void(EnemyActionPattern::*movementPtn[MOVEMENT_PTN_MAX])(Vector2f &pos, float speed, int cnt, int wait);

	int x = 1;
};
