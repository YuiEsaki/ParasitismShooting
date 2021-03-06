#include "Fish.h"
#include "../Game.h"
#include <DxLib.h>
#include "EnemyActionPattern.h"


Fish::Fish(const Player& player) : Enemy(player), player(player)
{
	ReadActionFile("action/fish.act");
	ChangeAction("eIdle");
	SetCharaSize(0.07f);
	charaData.shotReady = false;
	charaData.img = DxLib::LoadGraph(charaData.actData.imgFilePath.c_str());
	score = 200;

	actFlag = true;
	eAction.reset(new EnemyActionPattern());

	updater = &Fish::Move;
}

Fish::Fish(const Fish& d) : Enemy(d.player), player(player)
{
	*this = d;
}

void Fish::operator=(const Fish& d)
{
	memcpy(this, &d, sizeof(Fish));
}

Enemy * Fish::Clone()
{
	return new Fish(*this);
}

void Fish::Move()
{
	if (charaData.shotReady == true)
	{
		charaData.shotReady = false;
	}

	eAction->Update(movePtn, pos, charaData.moveVel, cnt, wait, shotCnt, charaData.SP, charaData.shotReady);
	cnt++;
}

void Fish::Die()
{
	scoreFlag = true;
	lifeFlag = false;
	actFlag = false;
}

void Fish::Stunning()
{
	eAction->Update(movePtn, pos, charaData.moveVel, cnt, wait, shotCnt, charaData.SP, charaData.shotReady);
	if (charaData.shotReady == true)
	{
		charaData.shotReady = false;
	}
}

void Fish::StunDamage()
{
	--charaData.SP;
	if (charaData.SP <= 0)
	{
		if (charaData.shotType == "WeakNormal")
		{
			charaData.shotType = "Normal";
		}
		else if (charaData.shotType == "WeakShotgun")
		{
			charaData.shotType = "Shotgun";
		}
		updater = &Fish::Stunning;
	}
}

Fish::~Fish()
{
}

void Fish::Update()
{
	(this->*updater)();
}

void Fish::Draw(int time)
{
	if (updater != &Fish::Stunning)
	{
		CharacterObject::Draw(charaData.img);
	}
	else
	{
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, std::abs((time * 5 % 255) - 127) + 128);
		CharacterObject::Draw(charaData.img);
		DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	}
}

void Fish::Damage()
{
	charaData.HP -= 1;
	if (charaData.HP <= 0)
	{
		updater = &Fish::Die;
	}
}
