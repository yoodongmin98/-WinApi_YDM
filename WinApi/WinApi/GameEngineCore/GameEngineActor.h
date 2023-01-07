#pragma once
#include <GameEngineBase/GameEngineMath.h>
#include <Windows.h>

// ȭ�鿡 �����ϰ� ��ġ�� �־���ϴ� ���͵��� �⺻����� �������� �̴ϴ�.
// �׷����� �Ѵ�.

// ���� :
class GameEngineLevel;
class GameEngineActor
{
	friend GameEngineLevel;

public:
	// constrcuter destructer
	GameEngineActor();
	~GameEngineActor();

	// delete Function
	GameEngineActor(const GameEngineActor& _Other) = delete;
	GameEngineActor(GameEngineActor&& _Other) noexcept = delete;
	GameEngineActor& operator=(const GameEngineActor& _Other) = delete;
	GameEngineActor& operator=(GameEngineActor&& _Other) noexcept = delete;

	float4 GetPos()
	{
		return Pos;
	}

	void SetPos(const float4& _MovePos)
	{
		Pos = _MovePos;
	}

	void SetMove(const float4& _MovePos)
	{
		Pos += _MovePos;
	}


protected:
	// �ȱ����Ҽ��� �ִ�.
	// ex) ������ Update�� �ȱ����Ҽ��� �ִ�.

	// �����ϱ����� ���� �غ��ؾ��Ұ��� ������ ���⼭ �ض�.
	virtual void Start() {}

	// Ű�Է��� �ްų� �ΰ������� ������ ����ϰų� �ϴ� �͵��� ���⼭ ó��
	virtual void Update() {}

	// ȭ�鿡 �׷����� ��ɵ��� ���⼭ ó��
	virtual void Render() {}

private:
	float4 Pos = { 0.0f, 0.0f };
};

