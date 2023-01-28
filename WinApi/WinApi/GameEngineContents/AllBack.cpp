#include "AllBack.h"

#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>



AllBack::AllBack()
{
	SetPos(GameEngineWindow::GetScreenSize().half()); //배경에서 액터를 로드했을때 기본위치값
}

AllBack::~AllBack()
{
}

GameEngineRender* AllBack::CreateRender(const std::string_view& _Image, int _Order)
{
	GameEngineRender* RD = GameEngineActor::CreateRender(_Image, _Order);
	RD->SetScale(GameEngineWindow::GetScreenSize());
	AllRender.push_back(RD);  //render의actor의vector ->pushback으로 하나씩넣음 >>reserve는?
	return RD;
}