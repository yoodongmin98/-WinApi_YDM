#include "IsaacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include "IsaacPlay.h"
#include "IsaacTitle"


// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// 중간에 절대로 지워지지 않을애를 포인터형으로 만들어서 동적할당해서 사용한다는건
// 제가보기에는 왜??? 그래야하지?
IsaacCore IsaacCore::Core;

IsaacCore::IsaacCore()
{
}

IsaacCore::~IsaacCore()
{
}

void IsaacCore::Start()
{
	//윈도우 사이즈를 정할수있음.
	GameEngineWindow::SettingWindowSize({ 1200.0f, 800.0f });

	new int();

	CreateLevel<IsaacTitle>("Title");
	CreateLevel<OpenningLevel>("Openning");
	CreateLevel<PlayLevel>("Play");
	ChangeLevel("Play");

	// static_assert
	// CreateLevel<HPlayer>("Title1");
}

void IsaacCore::Update()
{

}
void IsaacCore::End()
{

}