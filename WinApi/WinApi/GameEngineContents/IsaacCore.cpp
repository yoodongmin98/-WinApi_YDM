#include "IsaacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "IsaacIntro.h"
#include "TitleLevel.h"
#include "LoadLevel.h"



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

	new int();//릭이 제대로동작하는지 체크용
	GameEngineWindow::SettingWindowSize({ 1280, 720 });
	
	
	CreateLevel<IsaacIntro>("IsaacIntro");
	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<LoadLevel>("Loading");
	CreateLevel<IsaacLevel>("PlayIsaac");
	//보스몬스터방 들어가기전로딩
	//보스몬스터로딩후 다시 playlevel로돌아갈건지
	//아니면 새로운level을만들어서 넘어갈건지 >>편한대로
	ChangeLevel("IsaacIntro");
}

void IsaacCore::Update()
{

}
void IsaacCore::End()
{

}

//====================================================================