#pragma once
#include <memory>
#include "Scene/Scene.h"
#include "Geometry.h"


class Game
{
private:
	Game();							// 生成禁止
	Game(const Game&);				// ｺﾋﾟｰ禁止
	void operator=(const Game&);	// 代入禁止

	const Vector2 ScreenSize;
	float time, fps, count, oldcount;
	unsigned int fontSize;

	// fpsの表示
	void DrawFps();

public:
	// ｼﾝｸﾞﾙﾄﾝｲﾝﾀｰﾌｪｰｽ
	static Game& Instance()
	{
		static Game instance;
		return instance;
	}
	~Game();

	// 初期化系
	// 基本素材のﾛｰﾄﾞとか初期処理を行う
	void Initialize();

	// 中にﾙｰﾌﾟあり
	// これを呼ぶとｹﾞｰﾑが始まる
	void Run();

	// 後処理
	// ﾗｲﾌﾞﾗﾘの後処理や
	void Terminate();

	const Vector2& GetScreenSize()const;
};
