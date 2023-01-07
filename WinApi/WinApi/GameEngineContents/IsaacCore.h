#pragma once
#include <GameEngineCore/GameEngineCore.h>

// �̷��� Ŭ������ ����� ��� ����ü�� �̱����̶�� �մϴ�.

// ���� :
class IsaacCore : public GameEngineCore
{
public:
	// delete Function
	IsaacCore(const IsaacCore& _Other) = delete;
	IsaacCore(IsaacCore&& _Other) noexcept = delete;
	IsaacCore& operator=(const IsaacCore& _Other) = delete;
	IsaacCore& operator=(IsaacCore&& _Other) noexcept = delete;

	// �̱���
	static IsaacCore& GetInst()
	{
		return Core;
	}
protected:
	//GameEngineCore ��ӹ޾Ƽ�
	void Start() override; //�������̵��Ǵ� �Լ���°� ��������� �����ֱ�.
	void Update() override;
	void End() override;


private:
	// �����ڸ� ���� -> �� �Ѱ��ۿ� �����Ҽ��ۿ������Ѵ�.
	IsaacCore();
	~IsaacCore();

	// �ڱ⸦ �ڽ��� ������
	// ���α׷��� ��Ʋ� ���� 1���� ��ü�� ���������
	// static StudyGameCore* Core;
	static IsaacCore Core;

};

//�̱��� >>�����ڸ����� ���α׷������� �� 1���� �����Ҽ��ְ��Ѵ�
//static�̶� �� �ٸ��� ����...
