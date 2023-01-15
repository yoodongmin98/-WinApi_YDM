#include "TitleBack.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>

TitleBack::TitleBack()
{
}

TitleBack::~TitleBack()
{
}


void TitleBack::Start()
{
	float4 Size = GameEngineWindow::GetScreenSize(); //스크린사이즈를 Size에 받음


	GameEngineRender* Render = CreateRender("backtitle.bmp", IsaacOrder::BackGround);
	Render->SetPosition(GameEngineWindow::GetScreenSize().half());
	Render->SetScale(GameEngineWindow::GetScreenSize());
}