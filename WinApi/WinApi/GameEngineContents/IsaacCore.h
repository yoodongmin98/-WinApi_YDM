#pragma once
#include <GameEngineCore/GameEngineCore.h>

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

	// �����ͷ� ����ÿ��� �߰��� ������ �����ϴ�
	//static StudyGameCore& Destroy()
	//{
	//	delete Core;
	//}

protected:
	void Start() override;
	void Update() override;
	void End() override;


private:
	// �����ڸ� ����
	IsaacCore();
	~IsaacCore();

	
	// ���α׷��� ��Ʋ� ���� 1���� ��ü
	// static StudyGameCore* Core; �̰Ŷ�����
	static IsaacCore Core;

};

