#include "GameEngineCore.h"
#include <GameEngineBase/GameEngineDebug.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include "GameEngineLevel.h"

GameEngineCore* Core; 
//�ھ ���۵Ǹ� ���������� ����


//====================������,�Ҹ���===================

GameEngineCore::GameEngineCore()
{
	GameEngineDebug::LeakCheck(); //���۵Ǹ� leak check
	
	Core = this; //���ڽ��� ��´�.
}

GameEngineCore::~GameEngineCore()
{
	std::map<std::string, GameEngineLevel*>::iterator StartIter = Levels.begin(); //iterator�� ��ȸ���Ƽ�
	std::map<std::string, GameEngineLevel*>::iterator EndIter = Levels.end(); //begin��end���� ã��

	for (size_t i = 0; StartIter != EndIter; ++StartIter)
	{
		if (nullptr != StartIter->second)
		{
			delete StartIter->second; //������� new�������ϱ� ���鼭 ����
		}
	}
	Levels.clear(); // ????
}



//====================�����Լ��κ�============================

void GameEngineCore::GlobalStart()
{
	Core->Start(); //�ڽ��ʿ��� start�ΰ�(�����Լ�)
}

void GameEngineCore::GlobalUpdate()
{
	Core->Update();
	if (nullptr == Core->MainLevel) //���� ����� nullptr�̸�
	{
		MsgAssert("������ ���������� ���� ���·� �ھ �����߽��ϴ�"); //������
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
//������ �����ϴ��Լ�
void GameEngineCore::CoreStart(HINSTANCE _instance)
{
	GameEngineWindow::WindowCreate(_instance, "MainWindow", { 1280, 720 }, { 0, 0 });
	GameEngineWindow::WindowLoop(GameEngineCore::GlobalStart, GameEngineCore::GlobalUpdate, GameEngineCore::GlobalEnd);
}

//==============================================================
//�����ȯ
void GameEngineCore::ChangeLevel(const std::string_view& _Name)
{
	std::map<std::string, GameEngineLevel*>::iterator FindIter = Levels.find(_Name.data());

	if (FindIter == Levels.end())//�־��� �̸��� ��ã�Ҵٸ�(ã�����ϴ� ��尡 ���� ������ ���ٸ�)
	{
		std::string Name = _Name.data();
		MsgAssert(Name + "�������� �ʴ� ������ �����Ű���� �߽��ϴ�");
		return;
	}

	MainLevel = FindIter->second;
}
//==============================================================

void GameEngineCore::LevelLoading(GameEngineLevel* _Level)
{
	if (nullptr == _Level)
	{
		MsgAssert("nullptr �� ������ �ε��Ϸ��� �߽��ϴ�.");
		return;
	}

	_Level->Loading();
}