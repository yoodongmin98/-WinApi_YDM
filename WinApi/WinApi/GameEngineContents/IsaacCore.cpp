#include "IsaacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include "IsaacLevel.h"
#include "IsaacIntro.h"


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
	CreateLevel<IsaacIntro>("IsaacIntro");
	CreateLevel<IsaacLevel>("IsaacPlay");
	ChangeLevel("IsaacIntro");
}

void IsaacCore::Update()
{

}
void IsaacCore::End()
{

}

//====================================================================