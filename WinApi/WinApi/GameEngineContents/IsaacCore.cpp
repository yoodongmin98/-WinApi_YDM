#include "IsaacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "IsaacPlay.h"
#include "IsaacTitle.h"
#include "IsaacOpenning.h"

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
	// 정수의 연산 결과값은? 무조건 정수만 나옵니다.
	// 실수 1.2 원한다면 
	GameEngineWindow::SettingWindowSize({ 1200.0f, (1200.0f / 800.0f) * 600.0f });

	new int();

	CreateLevel<IsaacTitle>("Title");
	CreateLevel<IsaacOpenning>("Openning");
	CreateLevel<IsaacPlay>("Play");
	// static_assert
	// CreateLevel<HPlayer>("Title1");
	ChangeLevel("Play");
}

void IsaacCore::Update()
{

}
void IsaacCore::End()
{

}