#pragma once
#include "Geometry.h"

class Score
{
private:
	Score();						// 生成禁止
	Score(const Score&);			// ｺﾋﾟｰ禁止
	void operator=(const Score&);	// 代入禁止

	unsigned int nowScore;		// 現在のスコア
	unsigned int upScore;		// スコアの上昇値
	unsigned int highScore;		// 歴代の最高スコア
	unsigned int cCount;		// コンティニュー回数

public:
	static Score& Instance()
	{
		static Score instance;
		return instance;
	}
	~Score();

	void Update();
	void Draw(const Vector2& pos);

	// スコアの初期化, コンティニュー時に使う
	void InitScore(const bool& flag = false);

	void AddScore(const unsigned int& inscore);
	void AddContinueCount();

	// ステージクリアボーナス
	void AddClearBonus(const unsigned int& stagenum, const unsigned int& parasnum, const int& bosshp, const int& diff);
	
	unsigned int GetNowScore()const;
	unsigned int GetHighScore()const;
	unsigned int GetContinueCount()const;

	unsigned int stageBonus;
	unsigned int parasBonus;
	unsigned int bossHpBonus;
	int contBonus;
	float diffBonus;
	int bonusScore;
};

