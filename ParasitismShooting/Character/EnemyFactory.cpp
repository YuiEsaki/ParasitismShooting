#include "EnemyFactory.h"
#include "Fish.h"


ELegion & EnemyFactory::GetLegion()
{
	return legion;		// 集合体を返す
}

void EnemyFactory::EnemyDelete()
{
	for (int i = 0; i < legion.size(); ++i)
	{
		auto shot = *std::next(legion.begin(), i);
		if (!shot->GetLifeFlag())
		{
			legion.erase(std::next(legion.begin(), i));
			--i;
		}
	}
}

EnemyFactory::EnemyFactory(const Player& player) : player(player)
{
	originalEnemy["fish"] = new Fish(player);
}


EnemyFactory::~EnemyFactory()
{
}

Enemy * EnemyFactory::Create(const char * enemyname, Vector2f pos, int movePtn, int cnt, int wait, int hp, int sp, float speed)
{
	if(originalEnemy.find(enemyname) != originalEnemy.end())
	{
		auto enemy = originalEnemy[enemyname]->Clone();
		enemy->pos = pos;
		enemy->movePtn = movePtn;
		enemy->cnt = cnt;
		enemy->wait = wait;
		enemy->HP = hp;
		enemy->SP = sp;
		//enemy->vel = speed;
		legion.push_back(enemy);

		return enemy;
	}

	return nullptr;
}
