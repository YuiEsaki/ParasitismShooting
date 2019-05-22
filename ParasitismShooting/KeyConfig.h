#pragma once

enum ALL_KEY
{
	PAD_A,
	PAD_B,
	PAD_Y,
	PAD_X,
	PAD_L,
	PAD_R,
	PAD_START,
	PAD_SELECT,
	PAD_UP,
	PAD_RIGHT,
	PAD_DOWN,
	PAD_LEFT,
	ALL_KEY_MAX
};

enum USE_KEY
{
	ATTACK,		// U,č
	CANCEL,		// ń¶š,LZ
	BOMB,		// {
	SLOW,		// äĮ­čŚ®
	PAUSE,		// Q[f
	UP,			// Ŗ
	RIGHT,		// Ø
	DOWN,		// «
	LEFT,		// ©
	KEY_MAX
};



class KeyConfig
{
private:
	KeyConfig();
	KeyConfig(const KeyConfig&);
	void operator=(const KeyConfig&);
	
	int allKey[ALL_KEY_MAX];
	int defaultKey[KEY_MAX];
	int nowKey[KEY_MAX];


public:
	// ¼ŻøŽŁÄŻ²ŻĄ°ĢŖ°½
	static KeyConfig& Instance()
	{
		static KeyConfig instance;
		return instance;
	}

	~KeyConfig();

	int GetNowKey(const int& usekey);
	int GetAllKey(const int& usekey);

	void InitNowKey();

	void SetChangeKey(const int& oldkey, const int& newkey);
};

