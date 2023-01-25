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


// ==========================가상함수부분=============================
void IsaacCore::Start()
{
	new int();//릭이 제대로동작하는지 체크용

	
	
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