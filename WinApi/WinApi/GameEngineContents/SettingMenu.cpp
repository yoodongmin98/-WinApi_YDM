#include "Isaaclevel.h"
#include "AllBack.h"
#include "IsaacEnum.h"


#include <GameEnginePlatform/GameEngineInput.h>

#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineRender.h>



////���߿� ���������� ǥ���ϴ±���� ���⼭ ó��
void IsaacLevel::SettingMenuUpdate()
{
	AllBack* SetRender = CreateActor<AllBack>();
	//Menu
	SettingMenu=SetRender->CreateRender("Play_Settingmenu.BMP", IsaacOrder::R_Menu);
	

}
