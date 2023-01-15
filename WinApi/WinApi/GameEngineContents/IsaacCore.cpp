#include "IsaacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include "IsaacPlay.h"
#include "IsaacTitle.h"


IsaacCore IsaacCore::Core;

IsaacCore::IsaacCore()
{
}

IsaacCore::~IsaacCore()
{
}


// ==========================�����Լ��κ�=============================
void IsaacCore::Start()
{
	new int();//���� ����ε����ϴ��� üũ��

	
	GameEngineWindow::SettingWindowSize({ 1200.0f, 800.0f });
	CreateLevel<IsaacTitle>("Title");
	CreateLevel<IsaacPlay>("Play");
	ChangeLevel("Title");
}

void IsaacCore::Update()
{

}
void IsaacCore::End()
{

}

//====================================================================