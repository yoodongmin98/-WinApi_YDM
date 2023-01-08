#include "GameEngineLevel.h"
#include "GameEngineActor.h"
#include <GameEngineBase/GameEngineDebug.h>

GameEngineLevel::GameEngineLevel()
{
}

GameEngineLevel::~GameEngineLevel()
{
	// 편하게 for문을 돌리게 하기 위해서 17인부터 
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
//===============================actor관리============================
void GameEngineLevel::ActorStart(GameEngineActor* _Actor)
{
	if (nullptr == _Actor)
	{
		MsgAssert("nullptr 액터를 Start하려고 했습니다.");
		return;
	}

	_Actor->Start(); //헤도순환참조방지용 actor start
}

void GameEngineLevel::ActorsUpdate()//map안에서 for문돌면서 이름이같은node를찾았다면
{
	std::list<GameEngineActor*>::iterator StartIter = Actors.begin();
	std::list<GameEngineActor*>::iterator EndIter = Actors.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		(*StartIter)->Update();//그노드(액터)를 업데이트
	}
}

void GameEngineLevel::ActorsRender()
{
	std::list<GameEngineActor*>::iterator StartIter = Actors.begin();
	std::list<GameEngineActor*>::iterator EndIter = Actors.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		(*StartIter)->Render(); //똑같이 돌면서 렌더링
	}
}
//====================================================================