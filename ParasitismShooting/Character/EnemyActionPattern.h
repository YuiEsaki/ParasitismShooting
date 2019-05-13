#pragma once
#include "../Geometry.h"

class EnemyActionPattern
{
public:
	EnemyActionPattern();
	~EnemyActionPattern();
	void ActPattern0(Vector2f &pos, float speed, int cnt, int wait);		// 上下移動
	void ActPattern1(void);		// 左右に履ける
	void ActPattern2(void);		// 自機に特攻を仕掛ける
	void ActPattern3(void);		// 波状移動
	void ActPattern4(Vector2f &pos, float speed);		// 気絶状態
};
