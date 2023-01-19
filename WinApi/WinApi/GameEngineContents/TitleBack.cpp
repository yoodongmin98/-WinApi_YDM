#include "TitleBack.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <Windows.h>


TitleBack::TitleBack()
{
}

TitleBack::~TitleBack()
{
}


void TitleBack::Start()
{
	
	

	GameEngineRender* Render = CreateRender("BackTitle.BMP", IsaacOrder::BackGround);
	Render->SetPosition(GameEngineWindow::GetScreenSize().half());
	Render->SetScale(GameEngineWindow::GetScreenSize());
	
	
	GameEngineRender* Render1 = CreateRender("IsaacTitleTest.BMP", IsaacOrder::BackGround);
	Render1->SetPosition(GameEngineWindow::GetScreenSize().half());
	Render1->SetScale(GameEngineWindow::GetScreenSize());
	
	
}