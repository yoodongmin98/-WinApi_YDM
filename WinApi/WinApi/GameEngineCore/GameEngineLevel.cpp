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

	Actors.clear();
}

void GameEngineLevel::ActorStart(GameEngineActor* _Actor)
{
	if (nullptr == _Actor)
	{
		MsgAssert("nullptr ���͸� Start�Ϸ��� �߽��ϴ�.");
		return;
	}

	_Actor->Start();
}

void GameEngineLevel::ActorsUpdate()
{
	std::list<GameEngineActor*>::iterator StartIter = Actors.begin();
	std::list<GameEngineActor*>::iterator EndIter = Actors.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		(*StartIter)->Update();
	}
}

void GameEngineLevel::ActorsRender()
{
	std::list<GameEngineActor*>::iterator StartIter = Actors.begin();
	std::list<GameEngineActor*>::iterator EndIter = Actors.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		(*StartIter)->Render();
	}
}