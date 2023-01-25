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