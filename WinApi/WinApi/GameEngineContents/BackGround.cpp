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
		GameEngineRender* Render = CreateRender("BackGround.BMP", IsaacOrder::BackGround);
		Render->SetPosition(GameEngineWindow::GetScreenSize().half());
		Render->SetScale(GameEngineWindow::GetScreenSize());
	}



}