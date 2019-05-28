#include "SelectMenu.h"
#include <DxLib.h>
#include "Peripheral.h"
#include "Menu.h"
#include "KeyConfig.h"


SelectMenu::SelectMenu()
{
	menu.reset(new Menu());

	menu->menudata.push_back({ Vector2(menu->GetStringPosx("easy"), menu->ssize.y / 3 + 100), "easy", 0xff00ff });
	menu->menudata.push_back({ Vector2(menu->GetStringPosx("normal"), menu->ssize.y / 3 + 130), "normal", 0xff00ff });
	menu->menudata.push_back({ Vector2(menu->GetStringPosx("hard"), menu->ssize.y / 3 + 160), "hard", 0xff00ff });
	menu->menudata.push_back({ Vector2(menu->GetStringPosx("foolish"), menu->ssize.y / 3 + 190), "foolish", 0xff00ff });
}


SelectMenu::~SelectMenu()
{
}

bool SelectMenu::Update(const Peripheral & p)
{
	menu->Update(p);
	if (p.IsTrigger(KeyConfig::Instance().GetNowKey(ATTACK)) && !menu->decideFlag)
	{
		//if (menu->selcnt == 0)
		//{
		//	return true;
		//}
		//else if (menu->selcnt == 1)
		//{
		//	return true;
		//}
		menu->decideFlag = true;
		return true;
	}

	return false;
}

void SelectMenu::Draw()
{
	menu->Draw(Vector2(5, 5));
}
