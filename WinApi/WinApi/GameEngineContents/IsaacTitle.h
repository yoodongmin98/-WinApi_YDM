#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// ���� :
class IsaacTitle : public GameEngineLevel
{
public:
	// constrcuter destructer
	IsaacTitle();
	~IsaacTitle();

	// delete Function
	IsaacTitle(const IsaacTitle& _Other) = delete;
	IsaacTitle(IsaacTitle&& _Other) noexcept = delete;
	IsaacTitle& operator=(const IsaacTitle& _Other) = delete;
	IsaacTitle& operator=(IsaacTitle&& _Other) noexcept = delete;

protected:
	// ������ ����ħ ���� fm��� ����� �մϴ�.
	void Loading() override;
	void Update() override;

private:

};

