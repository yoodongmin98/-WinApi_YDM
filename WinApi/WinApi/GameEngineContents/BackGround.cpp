#include "BackGround.h"
#include"ContentsEnums.h"
#include<GameEnginePlatform/GameEngineWindow.h>
#include<GameEngineCore/GameEngineRender.h>

BackGround::BackGround()
{

}
BackGround::~BackGround()
{

}

void BackGround::Start()
{
	{
		GameEngineRender* BackGroundRender = CreateRender(IsaacOrder::BackGround);
		BackGroundRender->SetPosition(GameEngineWindow::GetScreenSize().half());
		BackGroundRender->SetScale(GameEngineWindow::GetScreenSize());
		BackGroundRender->CreateAnimation({ .AnimationName = "Back",  .ImageName = "BackGround.BMP" });
		BackGroundRender->ChangeAnimation("Back");
	}



}