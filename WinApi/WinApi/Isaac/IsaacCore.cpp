#include "IsaacCore.h"
#include <GameEnginePlatform/GameEngineWindow.h>

//#include "PlayLevel.h"
//#include "TitleLevel.h"
//#include "OpenningLevel.h"

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
	// ������ ���� �������? ������ ������ ���ɴϴ�.
	// �Ǽ� 1.2 ���Ѵٸ� 
	GameEngineWindow::SettingWindowSize({ 1200.0f, (1200.0f / 800.0f) * 600.0f });

	new int();

	/*CreateLevel<TitleLevel>("Title");
	CreateLevel<OpenningLevel>("Openning");
	CreateLevel<PlayLevel>("Play");
	ChangeLevel("Play");*/

	// static_assert
	// CreateLevel<HPlayer>("Title1");
}

void IsaacCore::Update()
{

}
void IsaacCore::End()
{

}