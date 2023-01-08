#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// 설명 :
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
	// 문법은 지나침 없이 fm대로 적어야 합니다.
	void Loading() override;
	void Update() override;

private:

};

