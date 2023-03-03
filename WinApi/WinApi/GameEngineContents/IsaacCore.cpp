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


// ==========================�����Լ��κ�=============================
void IsaacCore::Start()
{
	//�����̱� W,A,S,D
	//ȭ��ѱ�� SPACE �ڷΰ��� ESC
	//��ź E
	//����Ű �����¿�
	//����1 = ��ź,����,��Ʈ �����

	new int();//���� ����ε����ϴ��� üũ��
	GameEngineWindow::SettingWindowSize({ 1280, 720 });
	
	
	CreateLevel<IsaacIntro>("IsaacIntro");
	CreateLevel<TitleLevel>("TitleLevel");
	CreateLevel<LoadLevel>("Loading");
	CreateLevel<IsaacLevel>("PlayIsaac");
	//�������͹� �������ε�
	//�������ͷε��� �ٽ� playlevel�ε��ư�����
	//�ƴϸ� ���ο�level������ �Ѿ���� >>���Ѵ��
	ChangeLevel("IsaacIntro");
}

void IsaacCore::Update()
{

}
void IsaacCore::End()
{

}

//====================================================================