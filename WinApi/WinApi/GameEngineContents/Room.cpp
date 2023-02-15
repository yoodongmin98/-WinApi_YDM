#include "Room.h"
#include"IsaacEnum.h"
#include<GameEnginePlatform/GameEngineWindow.h>
#include<GameEnginePlatform/GameEngineInput.h>
#include<GameEngineCore/GameEngineRender.h>
#include "Isaaclevel.h"

Room::Room()
{

}
Room::~Room()
{

}

void Room::Start()
{
	{
		GameEngineRender* Render = CreateRender("Room.BMP", IsaacOrder::R_BackGround);
		Render->SetPosition(Render->GetImage()->GetImageScale().half());
		Render->SetScaleToImage();
	}
}