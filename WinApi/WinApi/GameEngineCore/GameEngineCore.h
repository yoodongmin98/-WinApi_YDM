#pragma once
#include <Windows.h>
#include <map>
#include <string_view>
#include <GameEngineBase/GameEngineDebug.h>

//�ھ�� ���Ѱ�
//�߻�Ŭ������ ����.
class GameEngineLevel;
class GameEngineCore
{
private:
	static void GlobalStart();
	static void GlobalUpdate();
	static void GlobalEnd();

public:
	// constrcuter destructer
	GameEngineCore();
	~GameEngineCore();

	// delete Function
	GameEngineCore(const GameEngineCore& _Other) = delete;
	GameEngineCore(GameEngineCore&& _Other) noexcept = delete;
	GameEngineCore& operator=(const GameEngineCore& _Other) = delete;
	GameEngineCore& operator=(GameEngineCore&& _Other) noexcept = delete;

	void CoreStart(HINSTANCE _instance);  //���ӽ�ŸƮ


protected:
	template<typename LevelType> //Ŭ���������� ������Ÿ���� ���ø�����.
	void CreateLevel(const std::string_view& _Name)
	{
		if (Levels.end() != Levels.find(_Name.data())) //find�� �����Ͱ� end���� �ٸ��ٸ� ������(�����̸��̴�.)
		{
			std::string Name = _Name.data(); 
			MsgAssert(Name + "�̹� �����ϴ� �̸��� ������ ������� �߽��ϴ�");
			return;
		}

		// ��ĳ����
		GameEngineLevel* Level = new LevelType(); //�������(Ŭ����)������ ������Ÿ���� ���ø����θ���.
		LevelLoading(Level);
		
		// insert�Ҷ����� ���ο� string�� ����鼭 �ڽŸ��� �޸𸮸� ������ ��/
		Levels.insert(std::make_pair(_Name.data(), Level));
	}

	void ChangeLevel(const std::string_view& _Name);

	virtual void Start() = 0;
	virtual void Update() = 0;
	virtual void End() = 0;

private:
	std::map<std::string, GameEngineLevel*> Levels;

	GameEngineLevel* MainLevel = nullptr;

	void LevelLoading(GameEngineLevel* _Level);

};

