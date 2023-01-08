#include "GameEngineLevel.h"
#include "GameEngineActor.h"
#include <GameEngineBase/GameEngineDebug.h>

GameEngineLevel::GameEngineLevel()
{
}

GameEngineLevel::~GameEngineLevel()
{
	// ���ϰ� for���� ������ �ϱ� ���ؼ� 17�κ��� 
	for (GameEngineActor* Actor : Actors)
	{
		// Actors.erase()
		if (nullptr != Actor)
		{
			delete Actor;
			Actor = nullptr;
		}
	}

	Actors.clear(); //??
}
//===============================actor����============================
void GameEngineLevel::ActorStart(GameEngineActor* _Actor)
{
	if (nullptr == _Actor)
	{
		MsgAssert("nullptr ���͸� Start�Ϸ��� �߽��ϴ�.");
		return;
	}

	_Actor->Start(); //�쵵��ȯ���������� actor start
}

void GameEngineLevel::ActorsUpdate()//map�ȿ��� for�����鼭 �̸��̰���node��ã�Ҵٸ�
{
	std::list<GameEngineActor*>::iterator StartIter = Actors.begin();
	std::list<GameEngineActor*>::iterator EndIter = Actors.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		(*StartIter)->Update();//�׳��(����)�� ������Ʈ
	}
}

void GameEngineLevel::ActorsRender()
{
	std::list<GameEngineActor*>::iterator StartIter = Actors.begin();
	std::list<GameEngineActor*>::iterator EndIter = Actors.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		(*StartIter)->Render(); //�Ȱ��� ���鼭 ������
	}
}
//====================================================================