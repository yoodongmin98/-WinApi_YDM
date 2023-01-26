#include "IsaacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "IsaacIntro.h"
#include "IsaacTitle.h"



#include "IsaacLevel.h"

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
	//CreateLevel<IsaacTitle>("IsaacTitle");

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