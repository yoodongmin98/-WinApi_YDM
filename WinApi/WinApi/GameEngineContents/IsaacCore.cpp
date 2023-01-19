#include "IsaacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include "IsaacLevel.h"
#include "IsaacTitle.h"


IsaacCore IsaacCore::Core;

IsaacCore::IsaacCore()
{
}

IsaacCore::~IsaacCore()
{
}


// ==========================가상함수부분=============================
void IsaacCore::Start()
{
	new int();//릭이 제대로동작하는지 체크용

	
	GameEngineWindow::SettingWindowSize({ 1200.0f, 800.0f });
	CreateLevel<IsaacTitle>("IsaacTitle");
	CreateLevel<IsaacLevel>("IsaacPlay");
	ChangeLevel("IsaacTitle");
}

void IsaacCore::Update()
{

}
void IsaacCore::End()
{

}

//====================================================================