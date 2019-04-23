#include "SelectScene.h"
#include <DxLib.h>
#include "../Peripheral.h"
#include "../Game.h"
#include "GamePlayingScene.h"

void SelectScene::FadeinUpdate(const Peripheral & p)
{
	if (p.IsTrigger(PAD_INPUT_8))
	{
		pal = 255;
		updater = &SelectScene::FadeoutUpdate;
	}
	
	if (pal == 255)
	{
		;
	}
	else
	{
		pal++;
	}
}

void SelectScene::FadeoutUpdate(const Peripheral & p)
{
	if (pal <= 0)
	{
		Game::Instance().ChangeScene(new GamePlayingScene());
	}
	else
	{
		pal -= 20;
	}
}

SelectScene::SelectScene()
{
	img = DxLib::LoadGraph("img/bg.png");
	updater = &SelectScene::FadeinUpdate;
}


SelectScene::~SelectScene()
{
}

void SelectScene::Update(const Peripheral& p)
{
	(this->*updater)(p);

	DxLib::SetDrawBlendMode(DX_BLENDMODE_ALPHA, pal);
	DxLib::DrawExtendGraph(0, 0, Game::Instance().GetScreenSize().x, Game::Instance().GetScreenSize().y, img, true);
	DxLib::DrawString(50, 50, "SelectScene", 0x000000);

}