#include "Isaaclevel.h"
#include "AllBack.h"
#include "IsaacEnum.h"


#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>



////나중에 먹은아이템 표시하는기능을 여기서 처리
void IsaacLevel::SettingMenuUpdate()
{
	AllBack* SetRender = CreateActor<AllBack>();
	//Menu
	SettingMenu=SetRender->CreateRender("Play_Settingmenu.BMP", IsaacOrder::R_Menu);
	

}
