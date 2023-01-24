#include "IntroBack.h"
#include "IsaacEnum.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <Windows.h>


IntroBack::IntroBack()
{
	SetPos(GameEngineWindow::GetScreenSize().half());
}

IntroBack::~IntroBack()
{
}

GameEngineRender* IntroBack::CreateRender(const std::string_view& _Image, int _Order)
{
	GameEngineRender* Render = GameEngineActor::CreateRender(_Image, _Order);
	Render->SetScale(GameEngineWindow::GetScreenSize());
	BackRender.push_back(Render);
	return Render;
}