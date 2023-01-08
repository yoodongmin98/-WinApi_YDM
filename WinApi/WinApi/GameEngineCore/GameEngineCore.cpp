#include "GameEngineCore.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "GameEngineLevel.h"

GameEngineCore* Core; 
//코어가 시작되면 전역변수를 선언


//====================생성자,소멸자===================

GameEngineCore::GameEngineCore()
{
	GameEngineDebug::LeakCheck(); //시작되면 leak check
	
	Core = this; //나자신을 담는다.
}

GameEngineCore::~GameEngineCore()
{
	std::map<std::string, GameEngineLevel*>::iterator StartIter = Levels.begin(); //iterator로 순회돌아서
	std::map<std::string, GameEngineLevel*>::iterator EndIter = Levels.end(); //begin과end값을 찾기

	for (size_t i = 0; StartIter != EndIter; ++StartIter)
	{
		if (nullptr != StartIter->second)
		{
			delete StartIter->second; //헤더에서 new해줬으니까 돌면서 삭제
		}
	}
	Levels.clear(); // ????
}



//====================가상함수부분============================

void GameEngineCore::GlobalStart()
{
	Core->Start(); //자식쪽에서 start로감(가상함수)
}

void GameEngineCore::GlobalUpdate()
{
	Core->Update();
	if (nullptr == Core->MainLevel) //메인 장면이 nullptr이면
	{
		MsgAssert("레벨을 지정해주지 않은 상태로 코어를 실행했습니다"); //터진당
		return;
	}

	Core->MainLevel->ActorsUpdate();
	Core->MainLevel->ActorsRender();
}

void GameEngineCore::GlobalEnd()
{
	Core->End();
}

//============================================================
//윈도우 시작하는함수
void GameEngineCore::CoreStart(HINSTANCE _instance)
{
	GameEngineWindow::WindowCreate(_instance, "MainWindow", { 1280, 720 }, { 0, 0 });
	GameEngineWindow::WindowLoop(GameEngineCore::GlobalStart, GameEngineCore::GlobalUpdate, GameEngineCore::GlobalEnd);
}

//==============================================================
//장면전환
void GameEngineCore::ChangeLevel(const std::string_view& _Name)
{
	std::map<std::string, GameEngineLevel*>::iterator FindIter = Levels.find(_Name.data());

	if (FindIter == Levels.end())//넣어준 이름을 못찾았다면(찾고자하는 노드가 맵의 끝노드와 같다면)
	{
		std::string Name = _Name.data();
		MsgAssert(Name + "존재하지 않는 레벨을 실행시키려고 했습니다");
		return;
	}

	MainLevel = FindIter->second;
}
//==============================================================

void GameEngineCore::LevelLoading(GameEngineLevel* _Level)
{
	if (nullptr == _Level)
	{
		MsgAssert("nullptr 인 레벨을 로딩하려고 했습니다.");
		return;
	}

	_Level->Loading();
}