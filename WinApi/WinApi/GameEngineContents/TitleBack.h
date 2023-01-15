#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ���� :
class TitleBack : public GameEngineActor //object��ӹ��� actor�����
{
public:
	// constrcuter destructer
	TitleBack();
	~TitleBack();

	// delete Function
	TitleBack(const TitleBack& _Other) = delete;
	TitleBack(TitleBack&& _Other) noexcept = delete;
	TitleBack& operator=(const TitleBack& _Other) = delete;
	TitleBack& operator=(TitleBack&& _Other) noexcept = delete;

protected:
	void Start() override; 

private:
};

