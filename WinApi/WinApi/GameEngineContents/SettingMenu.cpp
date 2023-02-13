#include "Isaaclevel.h"
#include "AllBack.h"
#include "IsaacEnum.h"

#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineInput.h>





void IsaacLevel::SettingMenuUpdate()
{
	AllBack* SetRender = CreateActor<AllBack>();
	SettingMenu = SetRender->CreateRender("Play_Settingmenu.BMP", IsaacOrder::R_Menu);
	SettingMenu->Off();
	SettingMenuCursor = SetRender->CreateRender("Play_Settingmenu.BMP", IsaacOrder::R_Menu);
	SettingMenuCursor->Off();
	if (false == GameEngineInput::IsKey("LoadMenu"))
	{
		GameEngineInput::CreateKey("LoadMenu", VK_ESCAPE);
	}
	if (true == GameEngineInput::IsDown("LoadMenu"))
	{
		SettingMenu->On();
	}
	
}