#include "IsaacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "IsaacIntro.h"
#include "TitleLevel.h"
#include "LoadLevel.h"
#include "BossLoding.h"
#include "MomBossLoad.h"
#include "NextLevelLoding.h"



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
	//움직이기 W,A,S,D
	//화면넘기기 SPACE 뒤로가기 ESC
	//폭탄 E
	//공격키 상하좌우
	//숫자1 = 폭탄,열쇠,하트 디버그
	//숫자2 = 무적모드(근데맵이동을못함 ㅋㅋ)
	//숫자3 = 무적모드해제
	// R	= 플레이어 이동속도 빨라짐

	new int();//릭이 제대로동작하는지 체크용
	GameEngineWindow::SettingWindowSize({ 1280, 720 });
	
	
	CreateLevel<IsaacIntro>("IsaacIntro");
	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<LoadLevel>("Loading");

	CreateLevel<IsaacLevel>("PlayIsaac"); //Stage1

	CreateLevel<BossLoadLevel>("BossLoad");
	CreateLevel<MomBossLoadLevel>("MomBossLoad");


	CreateLevel<NextLevelLoding>("NextLevelLoad");

	


	


	ChangeLevel("PlayIsaac");
}

void IsaacCore::Update()
{

}
void IsaacCore::End()
{

}

//====================================================================