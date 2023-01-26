#include "AllBack.h"
#include "IsaacEnum.h"
#include <GameEngineCore/GameEngineRender.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <Windows.h>


AllBack::AllBack()
{
	SetPos(GameEngineWindow::GetScreenSize().half()); //��濡�� ���͸� �ε������� �⺻��ġ��
}

AllBack::~AllBack()
{
}

GameEngineRender* AllBack::CreateRender(const std::string_view& _Image, int _Order)
{
	GameEngineRender* Render = GameEngineActor::CreateRender(_Image, _Order);
	Render->SetScale(GameEngineWindow::GetScreenSize());
	AllRender.push_back(Render);
	return Render;
}