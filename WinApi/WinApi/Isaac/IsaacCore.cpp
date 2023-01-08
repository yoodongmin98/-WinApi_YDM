#include "IsaacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include "IsaacPlay.h"
#include "IsaacTitle"


// StudyGameCore StudyGameCore::Core = new StudyGameCore();

// �߰��� ����� �������� �����ָ� ������������ ���� �����Ҵ��ؼ� ����Ѵٴ°�
// �������⿡�� ��??? �׷�������?
IsaacCore IsaacCore::Core;

IsaacCore::IsaacCore()
{
}

IsaacCore::~IsaacCore()
{
}

void IsaacCore::Start()
{
	//������ ����� ���Ҽ�����.
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