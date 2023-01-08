#include "IsaacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

#include "IsaacPlay.h"
#include "IsaacTitle.h"
#include "IsaacOpenning.h"

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
	new int();//���� ����ε����ϴ��� üũ��

	
	GameEngineWindow::SettingWindowSize({ 1200.0f, 800.0f });
	CreateLevel<IsaacTitle>("Title");
	CreateLevel<IsaacOpenning>("Openning");
	CreateLevel<IsaacPlay>("Play");
	ChangeLevel("Play");
}

void IsaacCore::Update()
{

}
void IsaacCore::End()
{

}