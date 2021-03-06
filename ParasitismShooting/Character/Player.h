#pragma once
#include <memory>
#include "../Geometry.h"
#include "CharacterObject.h"
#include "../KeyConfig.h"


enum Dir
{
	DIR_UP,
	DIR_RIGHT,
	DIR_DOWN,
	DIR_LEFT,
	DIR_MAX
};

class Peripheral;
class GamePlayingScene;
class GameScreen;


class Player : public CharacterObject
{
	friend GamePlayingScene;
private:
	// 状態遷移のためのメンバ関数ポインタ
	void (Player::*updater)(const Peripheral &p);
	void Move(const Peripheral &p);
	void Damage(const Peripheral &p);		// ダメージくらった
	void Invincible(const Peripheral &p);	// 無敵時間
	void Die(const Peripheral &p);			// 敵機又は弾に当たって死んだ
	void Reborn(const Peripheral &p);		// 復活
	void Parasitic(const Peripheral &p, const CharaData& cdata);	// 寄生
	void ParasiticCancel(const Peripheral &p);		// 寄生解除

	void Init();	// 2つのコンストラクタの共通部分
	void NotOutOfRange();		// 範囲外に行かせない

	CharaData originData;		// 寄生前の元々のデータ
	Vector2f startPos;			// 開始座標

	bool parasFlag;				// 寄生中か否か
	bool pinchFlag;				// 寄生解除されたらtrueになる

	int icount;
	int ccount;

	// 移動範囲限界値
	int up;
	int right;
	int left;
	int down;

	std::shared_ptr<GameScreen> gs;
	KeyConfig& key = KeyConfig::Instance();
	
public:
	// ステージ1で使うインスタンス(初期は何にも寄生していないため)
	Player();
	// ステージ2以降で使うインスタンス(前ステージの最後の寄生状態を持ってくる)
	Player(const CharaData& cdata);
	~Player();

	void Update(const Peripheral &p);
	void Draw(const int& time);
	void ParasDraw(const int& time);
};
